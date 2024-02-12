.data
# data goes here
fib_in: .dword 0xa #the 3rd fibonacci number
fib_out: .dword 0 #output is stored here

.section .text
.global main

main:
addi sp, sp, -0x8 #create stack frame
sd ra, 0(sp) #store return address of main
ld a0, fib_in #load the argument in the a0 reg

jal ra, fib #call the function with a0 = fib_in

la t1, fib_out #take the return value from the a1 reg 
sd a1, 0(t1) #store the return value in the required place
ld ra, 0(sp) #load the return address
addi sp, sp, 0x8 #restore stack frame
ret

fib: #fib(k)

addi sp, sp, -0x20 #make the stack frame

sd ra, 0(sp) #store the return address
sd a0, 0x8(sp) #store the argument

li t0, 2 #if a0 == 1 || a0 == 2
bleu a0, t0, fib_done #leave

addi a0, a0, -0x1 #a0 = a0 - 1
jal ra, fib #fib(k - 1)
sd a1, 0x10(sp) #t1 = fib(k-1)

addi a0, a0, -0x1 #store fib(k - 1)
jal ra, fib #fib(k - 2)
sd a1, 0x18(sp) #store fib(k - 2)

ld t1, 0x10(sp)
ld t2, 0x18(sp)
add a1, t2, t1 #a1 = fib(k - 1) + fib(k - 2)
  

ld ra, 0(sp) #restore return address
ld a0, 0x8(sp) #restore a0
addi sp, sp ,0x20 #restore stack frame
ret

fib_done:
ld ra, 0(sp) #restore return address
ld a0, 0x8(sp) #restore 
li a1, 0x1 #send value
addi sp, sp, 0x20 #restore stack frame

ret
