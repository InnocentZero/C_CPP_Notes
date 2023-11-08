# asm

[Intel assembly 64 bit intro](https://www.intel.com/content/dam/develop/external/us/en/documents/introduction-to-x64-assembly-181178.pdf)

The processor supports the following data types:

- `Word`: 2 byte structure
- `Doubleword`: 4 byte structure
- `Quadword`: 8 byte structure
- `Paragraph`: 16 byte structure

## Addressing Data in Memory

The process through which the processor controls the execution of instructions is referred as the fetch-decode-execute cycle or the execution cycle. It consists of three continuous steps −

- Fetching the instruction from memory
- Decoding or identifying the instruction
- Executing the instruction

## Some Assembly commands and syntax

> Unless stated otherwise, instructions are written in intel assembly flavour.

- DX:AX notation means that the upper half bits are in DX and lower half in AX.

- `adc` Add with carry. Differs from `add` in the sense that carry flag is also added.
  - `adc %b %a` : addition into `%b` depending on the size `%b` can hold.
  - `%a` always has to be smaller than `%b`
- `add` Add without carry. Rest is same as above.

- `bsf %a %b` : bit scan forward. Finds and stores the index of the least significant bit of `%b` into `%a`. If `%b` is 0, `%a` is undefined. ZF flag is set to 0 if bit is found or 1 otherwise.
- `bsr` : bit scan reverse. Same as above for most significant bit.

- `bswap`: reverse the bits of the register.

- `bt %a %b` checks for bit at address `%a` and offset `%b`. Value is stored in carry flag.
- `btc`: do the same as above but complement the bit you fetched later on.
- `btr`: do the same as `bt` but set the position to 0.
- `bts`: do the same as `bt` but set the position to 1.

- `and/or/xor %a %b` Bitwise **and/or/xor** of the two arguments, stored in the first location. First has to be larger in bitwidth.

- `mov %a, %b` In GAS (AT&T), moves the value of `%a` (or `$a`) to `%b` (must be an address or a register). In intel flavor, moves value of `%b` (or `$b`) to `%a` (must be an address).

- `imul %a, %b` multiplies the contents of `%a` with `%b` and stores them in `%a`.

  - `imul` is signed multiply. `mul` is the unsigned variant.
  - `imul %a, %b, $1234` does `%a` = `%b`\*1234. Size is extended for the last two operands as and when needed.
  - `imul %a` simply multiplies `%a` with the contents of AX register and stores it in DX:AX.

- `idiv` is signed divide. `div` is the unsigned variant.

  - `idiv %a` where a is 8bit. In this case, AL stores quotient and AH stores remainder.
  - `idiv %a` where a is 16bit. In this case, AX stores quotient and DX stores remainder.

- `enter`: create a stack frame for a procedure.
- `call`: calls a procedure.

  - `call` pushes the address of the next instruction on the stack.
  - When the procedure encounters a `ret` (at the end of the procedure), it pops the stack into the instruction pointer. - This way, the next instruction the instruction pointer continues off from where the program left initially.

  <!---TODO: Figure out enter--->
  <!---TODO: Figure out branch and link--->

- `cbw/cwde/cdqe`: Convert byte to word, word to doubleword, doubleword to quadword. Acts on AX reg.

- `clc`: Clear carry flag.
- `cmc`: complement carry flag.
- `cld`: Clear direction flag.
- `cli`: clear interrupt flag.
- `fclex`: clear floating point exceptions.

- `cmove`: Conditional moves. Find the list [here](https://github.com/HJLebbink/asm-dude/wiki/CMOVcc)
- `cmp` compare two values and store the result accordingly (stores the `zero` flag to be one).
- `cmps` takes two for size of string, reads the size from DS:SI to ES:DI and changes flags accordingly.
  - has suffixes b,w,d,q for size suffixes.
- `cmpxchg %a %b`: compare and exchange. If AX is equal to `%a` then `%b` is loaded to `%a`. Otherwise `%a` is loaded into AX. ZF is set to 1 if they are equal or 0 otherwise.
  - Also has another variant dealing with 64 and 128 bit values. Except `%b` is implicitly taken to be CX:BX.

<!---TODO: CRC32 instruction--->

- `dec %a` decrement `%a` by 1.
- `inc %a` increment by 1.

- `f2xm1`: replace ST[0] with 2^ST[0] - 1.
- `fabs`: replace ST[0] with its mod.

- `fbld %a`: load a binary coded decimal from `%a` and push it to the top of FPU stack.
- `fbstp %a`: do the exact opposite of `fbld`.
- `fchs`: change sign of ST[0].
- `fcmov ST[0], ST[i]`: dependent on the condition on CF, ZF and PF.
- `fincstp`: increment stack top field. Effectively rotates the stack. **NOT** equivalent to popping.
- `fcom/fcomp` the syntax is same as `comp` but it compares the two floating points and modifies the flags instead.
- `ficom/ficomp %a` compares a floating point and a register. Works the same as `fcom`.
  <!---TODO: wtf is register stack--->
- `fadd/faddp/fiadd` floating point addition (followed by popping the register stack.)
  - `fadd %a` adds to ST[0] and stores it there.
  - `fadd ST[0] ST[i]` add ST[i] to ST[0] and store the result in ST[0].
  - `fadd ST[i] ST[0]` add ST[i] to ST[0] and store the result in ST[i].
  - If p in the end of the instruction, pop the register stack.
  - `fiadd` is the same as `fadd`'s first variant but take an int argument instead.
- `fsub/fsubp/fisub`: same as `fadd` variants but subtract instead.
- `fsubr/fsubrp/fisubr`: do reverse subtraction.
- `fdiv/fdivp/fidiv` same as `fadd` but divide.
- `fmul/fmulp/fimul`: same as `fdiv` but multiply instead.
- `fdivr/fdivrp/fidivr` same as `fdiv` but in reverse.
- `fild %a` load %a onto the register stack.
- `fprem`: replace ST[0] with ST[0]%ST[1].
- `fld %a` same as `fild` but loads a floating point instead.
  - has some specialized variants for pushing common constants.
- `fist/fistp %a` take ST[0] and store it in the memory location given. ST[0] is converted to a signed integer. The other one is a pop variant.
- `fst/fstp`: store ST[0] floating point into memory location.
- `fisttp %a` Do the same as above but truncate if it's floating point.
- `frndint`: round ST[0] to integer.
- `fcos`: replace ST[0] with its approximate cosine.
- `fsin`: replace ST[0] with its sine.
- `fsincos`: compute sine and cosine of ST[0]. Replace ST[0] with the sine and push cosine.
- `fptan`: Same as `fcos` but tangent.
- `fsqrt`: take sqrt of ST[0] and store the result in ST[0].
- `ftst`: Compare ST[0] with 0 and change C3 C2 C0 flags accodingly.
- `fxch`: exchange ST[i] with ST[0] if ST[i] is given, otherwise exchange ST[1] with ST[0].

- `fnop`: no floating point operation.
