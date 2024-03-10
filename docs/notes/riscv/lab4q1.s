.data
my_roll: .word 0xa
first_name: .asciz "Isfarul"
last_name: .asciz "Haque"
fav_num: .word 0x1f

.section .text
.global main

main:
addi sp, sp, -0x10 #create stack frame
sd ra, 0(sp) #store return address
sd fp, 0x8(sp) #store the previous frame pointer
add fp, sp, 0x10 #move the fp to the new base of the stack frame

la t0, roll
lw t1, my_roll
sw t1, 0(t0)

la a0, first_name
la a1, last_name
lw a2, fav_num
jal ra, print

ld ra, -0x10(fp) #recover the return address
ld fp, -0x8(fp) #recover the original frame pointer

ret
