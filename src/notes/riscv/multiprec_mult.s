.data
# data goes here
iter: .dword 0x2 # number of chunks
chunksize: .dword 0x8 # bytes of the chunk, in this case word
var1: .dword 0x2222222222222222
	.dword 0x0000000000003333
var2: .dword 0x10
	.dword 0x3
var3: .dword 0x0
	.dword 0x0
	.dword 0x0
	.dword 0x0

.section .text
.global main

main:
ld a1, iter 
ld a2, chunksize 
mul s1, a1, a2 #adjusting max iterations to account for chunk size
xor s2, s2, s2 #i = 0
xor s4, s4, s4 #carry = 0

outer_loop:
bgeu s2, s1, return #i < k or exit

la t1, var1 #t1 = &var1
add t1, t1, s2 #t1 = &var1 + i
ld t1, 0(t1) #t1 = var1[i]

xor s3, s3, s3 #j = 0

inner_loop:
bgeu s3, s1, inner_end # j < k or exit

la t2, var2 #t2 = &var2
add t2, t2, s3 #t2 = &var2 + j
ld t2, 0(t2) #t2 = var2[j]

mul t3, t1, t2 #lower bits of var1[i] * var2[j]
add t3, t3, s4 #add the previous carry here
mulh s4, t1, t2 #upper bits of var1[i] * var2[j] set as the new carry

la t4, var3 #t4 = &var3
add t4, t4, s2 #t4 = &var3 + i
add t4, t4, s3 #t4 = &var3 + i + j

ld t5, 0(t4) #fetch whatever the previous value in that block was
add t5, t5, t3 #add the current multiplication to that value
sd t5, 0(t4) #store the final result

add s3, s3, a2 #j = j + 1
j inner_loop

inner_end:
add s2, s2, a2 #i = i + 1
j outer_loop

return:
ret
