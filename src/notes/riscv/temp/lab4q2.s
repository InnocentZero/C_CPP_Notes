.data
#name: .asciz "Isfarul "
#ame: .asciz "Haque"

.bss 
.global dest_str
dest_str: .space 0x50 

.section .text
.global concat

#main:
#addi sp, sp, -0x10
#sd ra, 0(sp)
#sd fp, 0x8(sp)
#addi fp, sp, 0x10

#la a0, name
#la a1, ame

#jal ra, concat 

#ld ra, -0x10(fp) #recover the return address
#ld fp, -0x8(fp) #recover the original frame pointer
#addi sp, sp, 0x10
#ret

concat:
addi sp, sp, -0x10 #create stack frame
sd ra, 0(sp) #store return address
sd fp, 0x8(sp) #store the previous frame pointer
addi fp, sp, 0x10

la a2, dest_str


copy_source:
lb t0, 0(a0)
beq t0, zero, end_strcat

sb t0, 0(a2)
addi a0, a0, 0x1
addi a2, a2, 0x1

j copy_source

end_strcat:

copy_append:
lb t0, 0(a1)
beq t0, zero, epilogue

sb t0, 0(a2)
addi a1, a1, 0x1
addi a2, a2, 0x1
j copy_append

epilogue:
sb zero, 0(a2)

ld ra, -0x10(fp) #recover the return address
ld fp, -0x8(fp) #recover the original frame pointer
addi sp, sp, 0x10
ret
