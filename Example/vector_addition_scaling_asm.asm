sub 0, 0, 0
addi 1, 0, 16
addi 2, 1, 16
addi 3, 2, 16
addi 4, 0, 0
addi 5, 0, -3
lw 6, 0(0)
lw 7, 0(1)
add 8, 6, 7
sll 8, 8, 2
sw 8, 0(2)
addi 0, 0, 4 
addi 1, 1, 4
addi 2, 2, 4
addi 5, 5, 1
blez 5, -40
EOF
