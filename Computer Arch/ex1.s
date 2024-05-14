.data
    str: .string: .asciiz "Hello, world \n"

.text
    #a0 e a1 sao registradores
    li a0, 4 #l1 guarda o valor e o 4 é o comando para printar
    la a1, str #la lê o endereço
    ecall #recebe linhas anteriores

    li a0, 11 #11 quebra a linha
    li a1, 13 #corresponde ao \n
    ecall #imprime uma e quebra a linha para imprimir a próxima

    li a0,10
    ecall   #Encerra o programa
    ret #retorna a função que o chamou