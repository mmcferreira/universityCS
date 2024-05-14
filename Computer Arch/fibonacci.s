# 14/05/2024
.data
    n: .word 6 #Numero de vezes que soma

.text
    main:
        lw a0, n    #carrega o valor de n, LER VALOR DA PALAVRA (WORD), representa quanta vezes soma
        li t0, 0    #f(0)
        li t1, 1    #f(1)
    
    
    for:
        beq a0, zero, fim   #se n == 0, termina
            add t2, t0, t1  #calcula f(n) - f(n-1) + f(n-2)
            mv t0, t1       #atualiza f(n-2) para o próximo loop
            mv t1,t2        #atualiza f(n-1) para o próximo loop
        addi a0, a0, -1     #descrementa n
    j for

    fim:
    #O resultado está em t1 (f(n))
    addi a0, x0, 1      #argumento para o ecall executar
    addi a1, t1, 0      #argumento para ecall, o valor a ser
    ecall               #imprime o ecall inteiro

    #Imprime um caractere de nova linha
    li a0, 11
    li a1, 13
    ecall
    
    li a0, 10
    ecall
    ret             #encerra o programa