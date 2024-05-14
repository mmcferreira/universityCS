.data
str: .string: .asciiz "\nSoma de 123 + 37 = "

.text
main:
    #soma
    addi t0, zero, 123 #t0 = 0+123
    addi t1, zero, 37  #t1 = 0 + 37
    add t2, t1, t0, # t2 =t1 + t0

    #imprime a mensagem str
    li a0, 4        #indica o que vai ser impresso, nesse caso 4 = string
    la a1, str
    ecall

    #O resultado está em t2
    addi a0, zero, 1  #indica o que vai ser impresso, nesse caso 1 = inteiro
    addi a1, t2, 0  #o valor a ser
    ecall           #imprimir ecall
    li a0, 11 #11 quebra a linha
    li a1, 13 #corresponde ao \n
    ecall #imprime uma e quebra a linha para imprimir a próxima

fim:
li a0, 10
ecall   #Encerra o programa
ret