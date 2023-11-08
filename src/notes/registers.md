# registers

## General Purpose Register

There are 3 types of General-purpose data registers they are:

### Data registers

Data registers consists of four 32-bit data registers, which are used for arithmetic, logical and other operations.

They are mostly used for storing temporary variables during instruction execution. They are mostly meant to do arithmetic manipulation.

Data registers are again classified into 4 types they are:

- AX: Accumulator register. Its bits are split into two registers, AH and AL, allowing it to execute half bit-width instructions as well.
- BX: Base register. Split into BH and BL.
- CX: Count register. This acts as a counter for loops.
- DX: This is known as the Data register. In I/O operations, the data register can be used as a port number.

### Pointer registers

The pointer registers consist of 16-bit left sections (SP, and BP) and 32-bit ESP and EBP registers.

They are mostly used for storing pointers.

- SP: This is known as a Stack pointer used to point the program stack. For accessing the stack segment, it works with SS. It has a 16-bit size. It designates the item at the top of the stack. The stack pointer will be (FFFE)H if the stack is empty. The stack segment is relative to its offset address.
- BP: This is known as the Base pointer used to point data in the stack segments. We can utilize BP to access data in the other segments, unlike SP. It has a 16-bit size. It mostly serves as a way to access parameters given via the stack. The stack segment is relative to its offset address.

### Index registers

The 16-bit rightmost bits of the 32-bit ESI and EDI index registers. SI and DI are sometimes employed in addition and sometimes in subtraction as well as for indexed addressing.

They are used for accessing memory segments where data needs to be read from and written to.

- SI: This source index register is used to identify memory addresses in the data segment that DS is addressing. Therefore, it is simple to access successive memory locations when we increment the contents of SI. It has a 16-bit size. Relative to the data segment, it has an offset.
- DI: The function of this destination index register is identical to that of SI. String operations are a subclass of instructions that employ DI to access the memory addresses specified by ES. It is generally used as a Destination index for string operations.

## Special Purpose Registers

To store machine state data and change state configuration, special purpose registers are employed. In other words, it is also defined as the CPU has a number of registers that are used to carry out instruction execution these registers are called special purpose registers. Special purpose registers are of 8 types they are cs, ds, ss, es, fs, and gs registers come under segment registers. These registers hold up to six segment selectors.

- CS (Code Segment register): A 16-bit register called a code segment (CS) holds the address of a 64 KB section together with CPU instructions. All accesses to instructions referred to by an instruction pointer (IP) register are made by the CPU using the CS segment. Direct changes to CS registration are not possible. When using the far jump, far call, and far return instructions, the CS register is automatically updated.
- DS (Data Segment register): A 64KB segment of program data is addressed using a 16-bit register called the data segment. The processor by default believes that the data segment contains all information referred to by the general registers (AX, BX, CX, and DX) and index registers (SI, DI). POP and LDS commands can be used to directly alter the DS register.
- SS (Stack Segment register): A 16-bit register called a stack segment holds the address of a 64KB segment with a software stack. The CPU by default believes that the stack segment contains all information referred to by the stack pointer (SP) and base pointer (BP) registers. POP instruction allows for direct modification of the SS register.
- ES (Extra Segment register): A 16-bit register called extra segment holds the address of a 64KB segment, typically holding program data. In string manipulation instructions, the CPU defaults to assuming that the DI register refers to the ES segment. POP and LES commands can be used to directly update the ES register.
- FS (File Segment register): FS registers don’t have a purpose that is predetermined by the CPU; instead, the OS that runs them gives them a purpose. On Windows processes, FS is used to point to the thread information block (TIB). On 64 bit unix systems, they are always 0.
- GS (Graphics Segment register): The GS register is used in Windows 64-bit to point to operating system-defined structures. OS kernels frequently use GS to access thread-specific memory. The GS register is employed by Windows to control thread-specific memory. In order to access CPU-specific memory, the Linux kernel employs GS. A pointer to a thread local storage, or TLS, is frequently used as GS.
- IP (Instruction Pointer register): The registers CS and IP are used by the 8086 to access instructions. The segment number of the following instruction is stored in the CS register, while the offset is stored in the IP register. Every time an instruction is executed, IP is modified to point to the upcoming instruction. The IP cannot be directly modified by an instruction, unlike other registers; an instruction may not have the IP as its operand.
