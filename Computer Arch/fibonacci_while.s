#21/05/24

.data
    n: .word 6 # Número de vezes que soma

.text
    main:
        lw a0, n    # Carrega o valor de n, representa quantas vezes soma
        li t0, 0    # f(0)
        li t1, 1    # f(1)
    
    while_start:
        beq a0, zero, while_end   # Se n == 0, termina
        add t2, t0, t1            # Calcula f(n) - f(n-1) + f(n-2)
        mv t0, t1                 # Atualiza f(n-2) para o próximo loop
        mv t1, t2                 # Atualiza f(n-1) para o próximo loop
        addi a0, a0, -1           # Decrementa n
        j while_start

    while_end:
        # O resultado está em t1 (f(n))
        addi a0, x0, 1       # Argumento para o ecall executar
        addi a1, t1, 0       # Argumento para ecall, o valor a ser impresso
        ecall                # Imprime o inteiro

    #Imprime um caractere de nova linha
    li a0, 11
    li a1, 13
    ecall
    
    li a0, 10
    ecall
    ret             #encerra o programa
