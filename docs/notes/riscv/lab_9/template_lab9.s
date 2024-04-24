
.section .text
.global main



main:
    # Prepare jump to super mode
    li t1, 1
    slli t1, t1, 11   #mpp_mask
    csrs mstatus, t1
    
    la t4, supervisor       #load address of user-space code
    csrrw zero, mepc, t4    #set mepc to user code
    
    la t5, page_fault_handler
    csrw mtvec, t5
   
    mret

supervisor:
################## Setting up page tables ##############
    # Set value in PTE2 (Initial Mapping)
    li a0,0x81000000
    li a1, 0x82000
    slli a1, a1, 0xa
    ori a1, a1, 0x01 # | - | - | - |V
    sd a1, 16(a0)

    # To set V.A 0x0 -> P.A 0x0
    li a1, 0x82001
    slli a1, a1, 0xa
    ori a1, a1, 0x01 # | - | - | - |V
    sd a1, 0(a0)

    # Set value in PTE1 (Initial Mapping)
    li a0,0x82000000
    li a1, 0x83000
    slli a1, a1, 0xa
    ori a1, a1, 0x01 # | - | - | - |V
    sd a1, 0(a0)

    # Set Frame number in PTE0 (Initial Mapping)
    li a0,0x83000000
    li a1, 0x80000
    slli a1, a1, 0xa
    ori a1, a1, 0xef # D | A | G | - | X | W | R |V
    sd a1, 0(a0)

    li a1, 0x80001
    slli a1, a1, 0xa
    ori a1, a1, 0xef # D | A | G | - | X | W | R |V
    sd a1, 8(a0)

    # Set value in PTE1 (Code Mapping)
    li a0,0x82001000
    li a1, 0x83001
    slli a1, a1, 0xa
    ori a1, a1, 0x01 # | - | - | - |V
    sd a1, 0(a0)

    # Set value in PTE0 (Code Mapping)
    li a0,0x83001000
    li a1, 0x80001
    slli a1, a1, 0xa
    ori a1, a1, 0xfb # D | A | G | U | X | - | R |V
    sd a1, 0(a0)

    # Data Mapping
    li a1, 0x80002
    slli a1, a1, 0xa
    ori a1, a1, 0xf7 # D | A | G | U | - | W | R |V
    sd a1, 8(a0)
    

####################################################################

    # Prepare jump to user mode
    li t1, 0
    slli t1, t1, 8   #spp_mask
    csrs sstatus, t1

    # Configure satp
    la t1, satp_config 
    ld t2, 0(t1)
    sfence.vma zero, zero
    csrrw zero, satp, t2
    sfence.vma zero, zero

    li t4, 0       # load VA address of user-space code
    csrrw zero, sepc, t4    # set sepc to user code
    
    sret



###################################################################
##################### ADD CODE ONLY HERE  #########################
###################################################################
.align 4
page_fault_handler:
csrrw s10, mtval, zero
csrrw s11, mcause, zero

li s9, 0xc

beq s11, s9, code_handler

data_handler:

srli s10, s10, 0xc # VA acts as an offset to PTE once right shifted by 12 bits
li s6, 0x8
mul s10, s10, s6 # and multiplied with PTE size
li a0, 0x83001000
add a0, a0, s10

li a1, 0x80002
slli a1, a1, 0xa
ori a1, a1, 0xf7 # D | A | G | U | - | W | R |V
sd a1, 0(a0)
    
mret

code_handler:

# copy page from 0x8000 1000 to 0x8000 1000 + VA
li s8, 0x80001000 # code page table

li s7, 0x80001000
add s7, s7, s10 # new page table = 0x80001000 + VA

xor s6, s6, s6 # i = 0
li s5, 0x1000 # i < 0x1000

loop:
bgeu s6, s5, loop_end # i < 0x1000
add s4, s8, s6 # s4 = 0x80001000 + i
ld s4, 0(s4) # s4 = *s4
add s3, s7, s6 # s3 = new page table + i
sd s4, 0(s3) # *s3 = s4
addi s6, s6, 0x8 # increment i by dword size
j loop

# add page table entry
loop_end:
srli s7, s7, 0xc # shift the new page address by 12 bits for adding a PTE
slli s7, s7, 0xa # right shift by 10 bits for permissions
ori s7, s7, 0xfb # D | A | G | U | X | - | R |V

srli s10, s10, 0xc # VA acts as offset to PTE once right shifted by 12 bits
li s6, 0x8
mul s10, s10, s6 # and multiplied with PTE size
li s6, 0x83001000
add s6, s6, s10 # new pte
sd s7, 0(s6) # writing the new PTE

mret

###################################################################
###################################################################



.align 12
user_code:
    la t1,var_count
    lw t2, 0(t1)
    addi t2, t2, 1
    sw t2, 0(t1)

    la t5, code_jump_position
    lw t3, 0(t5)
    li t4, 0x2000
    add t3, t3, t4
    sw t3, 0(t5)
    
    jalr x0, t3


.data
.align 12
var_count:  .word  0
code_jump_position: .word 0x0000


.align 8
# Value to set in satp
satp_config: .dword 0x8000000000081000
