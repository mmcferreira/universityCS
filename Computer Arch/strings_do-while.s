.data
    str1: .string "Teste de string"         #Define uma string chamada "str1" com o conteúdo "Teste de string"
    str2: .space 20                         #Aloca 20 bytes de memória para a string "str2" (valor inicial indefinido)
    str3: .string "Hello World"             #Define uma string chamada str3 com o conteúdo "Hello World"

.text
main:
    li a0, 4            #Configura o código da chamada do sistema para imprimir uma string
    la a1, str1         #Carrega o endereço da string "str1" no registrador a1
    ecall               #Chama o serviço do sistema para imprimir a string "Teste de string"

    li a0, 11            #Configura o código da chamada do sistema para imprimir um caractere
    li a1, 13            #Define o valor ASCII para o caractere da nova linha
    ecall               #Chama o serviço do sistema para imprimir o caractere da nova linha

#-------------------------------------------------------------------------------------------
    la s0, str2     #Carrega o endereço de string "str2" no registrador s0
    li s1, 20       #Inicializa o contador para 20 (número de bytes para serem guardados_
    li s3, 65       #Define o valor ASCII "A" (65) para preencher a string

do_while:
    sb s3, 0(s0)    #Armazena o valor de s3 no byte atual de "str2"
    addi s0, s0 , 1 #Avança para o próximo byte
    addi s1, s1, -1 #Decrementa o contador
bne s1, zero, do_while  #Repete o loop até que o ontador seja zero

    li a0, 4        #Configura o código da chamada do sistema para imprimir uma string
    la a1, str2     #Carrega o endereço da string "str2" no registrador a1
    ecall           #Chama o serviço para imprimir a string "AAAAAA"

    li a0, 11       #Configura a chamada do sistema pra imprimir um \n
    li a1, 13       #Define o valor ASCII para o caractere de nova linha
    ecall           #Chama o serviço do sistema para imprimir o \n
#-------------------------------------------------------------------------------------------
    li a0, 4            #Configura o código para imprimir uma string
    la a1, str3         #Carrega o endereço da string "str3" no registrador a1
    ecall               #Chama o serviço para imprimir a string "Hello World"

    li a0, 11            #Configura o código da chamada do sistema para imprimir um caractere
    li a1, 13            #Define o valor ASCII para o caractere da nova linha
    ecall               #Chama o serviço do sistema para imprimir o caractere da nova linha


    fim:
        li a0, 10
        ecall       #encerra o programa
        ret