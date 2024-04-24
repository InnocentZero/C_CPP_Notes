# got_plt

[Read this as well](https://www.technovelty.org/linux/plt-and-got-the-key-to-code-sharing-and-dynamic-libraries.html)

## Relocations

Relocations are entries in binaries that basically tell the linker to put stuff
there. It could be compile time linker for statically linked binaries or run-
time linker for dynamically linked stuff.

It basically says, "Determine the value of X., and put that value at offset Y".

### Link time example

```C
extern int foo;
int retfoo(void) {
  return foo;
}
```

```sh
gcc -c a.c
readelf --relocs ./a.o
```

```
Relocation section '.rel.text' at offset 0x2dc contains 1 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
00000004  00000801 R_386_32          00000000   foo
```

On running `objdump -D ./a.o`

```
./a.o:     file format elf32-i386


Disassembly of section .text:

00000000 <function>:
   0:    55         push   %ebp
   1:    89 e5                  mov    %esp,%ebp
   3:    a1 00 00 00 00         mov    0x0,%eax
   8:    5d                     pop    %ebp
   9:    c3                     ret
```

As you can see the value at `0x04` is 4 bytes of zeroes. These will be resolved
at linker phase, and the actual address will be added there.

### Run time example

```sh
readelf --headers /lib/libc.so.6
```

```
Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
[...]
  LOAD           0x000000 0x00000000 0x00000000 0x236ac 0x236ac R E 0x1000
  LOAD           0x023edc 0x00024edc 0x00024edc 0x0015c 0x001a4 RW  0x1000
```

As you can see, the addresses of the library are not resolved until runtime.
There is no specific base address. Only the offsets are specified.

Another goal is code sharing. We don't need 100 copies of the same library for
100 different processes.

At the same time, the data for each process attempting to access the shared
library must be unique.

This is what is accomplished by the offset in the elf section. Note that this
is virtual memory, so multiple processes can refer to the same address and still
have separate data sections for themselves.

In `AMD64` architecture you can directly move stuff with offset from current pc
into registers and other funky stuff, so it's easy. for `i386` architecture, you
need to load a fixed reference address, like load the stack pointer of a
function to get the fixed address.

An example of this behaviour in 32 bit architecture.

```
0000040c <function>:
 40c:    55         push   %ebp
 40d:    89 e5                  mov    %esp,%ebp
 40f:    e8 0e 00 00 00         call   422 <__i686.get_pc_thunk.cx>
 414:    81 c1 5c 11 00 00      add    $0x115c,%ecx
 41a:    8b 81 18 00 00 00      mov    0x18(%ecx),%eax
 420:    5d                     pop    %ebp
 421:    c3                     ret

00000422 <__i686.get_pc_thunk.cx>:
 422:    8b 0c 24       mov    (%esp),%ecx
 425:    c3                     ret
```
