.data
ma: .word 1,2,3
    .word 4,5,6
    .word 7,8,9

mb: .word 9,8,7
    .word 6,5,4
    .word 3,2,1

.text
main:
    la t0, ma
    la t1, mb
    
    li s7, 3

    li t3, 0
loop_i:
    li t4, 0
loop_j:
    li t5, 0
    li t6, 0

loop_k:
    mul s0, t3, s7
    add s0, s0, t6
    slli s0, s0, 2
    add s1, t0, s0
    lw a0, 0(s1)

    mul s0, t6, s7
    add s0, s0, t4
    slli s0, s0, 2
    add s1, t1, s0
    lw a1, 0(s1)

    mul a2, a0, a1
    add t5, t5, a2

    addi t6, t6, 1
    blt t6, s7, loop_k

    mul s0, t3, s7
    add s0, s0, t4
    slli s0, s0, 2
    add s1, t2, s0
    sw t5, 0(s1)

    addi t4, t4, 1
    blt t4, s7, loop_j

    addi t3, t3, 1
    blt t3, s7, loop_i

print_matriz:
    li t3, 0
print_i:
    li t4, 0
print_j:
    mul s0, t3, s7
    add s0, s0, t4
    slli s0, s0, 2
    add s1, t2, s0
    lw a0, 0(s1)

    li a7, 1
    ecall

    addi t4, t4, 1
    blt t4, s7, print_j

    li a7, 4
    la a0, 0
    ecall

    addi t3, t3, 1
    blt t3, s7, print_i

end:
