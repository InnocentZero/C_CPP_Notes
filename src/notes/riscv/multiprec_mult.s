### TODO: FIX THE LOGIC IT DOESN'T WORK
.data
# data goes here
iter: .word 0x2 # number of chunks
chunksize: .word 0x4 # bytes of the chunk, in this case word
var1: .word 0x2
	.word 0x0
var2: .word 0x3
	.word 0x0
var3: .word 0x0
	.word 0x0

.section .text
.global main

main:
lw a1, iter 
lw a2, chunksize 
mul s1, a1, a2
xor s2, s2, s2 #i = 0
xor s3, s3, s3 #carry = 0

loop:
bgeu s2, s1, return #i < k or exit

la t1, var1 #t1 = &var1
add t1, t1, s2 #t1 = &var1 + i
lw t1, 0(t1) #t1 = var1[i]

la t2, var2 #t2 = &var2
add t2, t2, s2 #t2 = &var2 + i
lw t2, 0(t2) #t2 = var2[i]

mul t3, t1, t2 #lower bits of mutiplication
add t3, t3, s3 #add carry over from prev multiplication
mulh s3, t1, t2 #upper bits of multiplication for next iteration


la t4, var3
add t4, t4, s2
sw t3, 0(t4) #store the final result

add s2, s2, a2
j loop

return:
ret
