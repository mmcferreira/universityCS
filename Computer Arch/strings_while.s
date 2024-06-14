.data
    str1: .string "Teste de string"         # Define uma string chamada "str1" com o conteúdo "Teste de string"
    str2: .space 20                         # Aloca 20 bytes de memória para a string "str2" (valor inicial indefinido)
    str3: .string "Hello World"             # Define uma string chamada "str3" com o conteúdo "Hello World"

.text
main:
    li a0, 4            # Configura o código da chamada do sistema para imprimir uma string
    la a1, str1         # Carrega o endereço da string "str1" no registrador a1
    ecall               # Chama o serviço do sistema para imprimir a string "Teste de string"

    li a0, 11           # Configura o código da chamada do sistema para imprimir um caractere
    li a1, 13           # Define o valor ASCII para o caractere da nova linha
    ecall               # Chama o serviço do sistema para imprimir o caractere da nova linha

#-------------------------------------------------------------------------------------------
    la s0, str2         # Carrega o endereço de string "str2" no registrador s0
    li s3, 65           # Define o valor ASCII "A" (65) para preencher a string

    li t0, 20           # Carrega o valor 20 no registrador t0 (para comparação)

# Implementação do loop `for` em Assembly
    li s1, 0            # Inicializa o contador (i = 0)

while_start:
    bge s1, t0, while_end  # Se o contador (s1) >= 20, termina o loop
    sb s3, 0(s0)        # Armazena o valor de s3 no byte atual de "str2"
    addi s0, s0 , 1     # Avança para o próximo byte
    addi s1, s1, 1      # Incrementa o contador (i++)

    j while_start        # Salta de volta para o início do loop
while_end:
    li a0, 4            # Configura o código da chamada do sistema para imprimir uma string
    la a1, str2         # Carrega o endereço da string "str2" no registrador a1
    ecall               # Chama o serviço para imprimir a string "AAAAAAAAAAAAAAAAAAAA"

    li a0, 11           # Configura a chamada do sistema pra imprimir um \n
    li a1, 13           # Define o valor ASCII para o caractere de nova linha
    ecall               # Chama o serviço do sistema para imprimir o \n
#-------------------------------------------------------------------------------------------
    li a0, 4            # Configura o código para imprimir uma string
    la a1, str3         # Carrega o endereço da string "str3" no registrador a1
    ecall               # Chama o serviço para imprimir a string "Hello World"

    li a0, 11           # Configura o código da chamada do sistema para imprimir um caractere
    li a1, 13           # Define o valor ASCII para o caractere da nova linha
    ecall               # Chama o serviço do sistema para imprimir o caractere da nova linha

fim:
    li a0, 10
    ecall               # Encerra o programa
    ret