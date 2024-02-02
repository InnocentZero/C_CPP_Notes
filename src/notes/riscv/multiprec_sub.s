.data
# data goes here
iter: .word 0x2 # number of chunks
chunksize: .word 0x4 # bytes of the chunk, in this case word
var1: .word 0xffffffff
	.word 0x53535353
var2: .word 0x1
	.word 0x01010101
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
bgeu s2, s1, return # i < k or exit

la t1, var1 #t1 = &var1
add t1, t1, s2 #t1 = &var1 + i
lw t1, 0(t1) #t1 = var1[i]

la t2, var2 #t2 = &var2
add t2, t2, s2 #t2 = &var2 + i
lw t2, 0(t2) #t2 = var2[i]

sub t3, t1, t2 #sum = var1[i] - var2[i]
sgtu s4, t3, t1 #first carry

sub t4, t3, s3 #sum = sum + carry
sgtu s5, t4, t3 #second carry

add s3, s4, s5 #final carry

la t3, var3
add t3, t3, s2
sw t4, 0(t3)

add s2, s2, a2
j loop

return:
ret
