#14/05/2024
.data
numeros: .word 30, 8, 3, 12, 25 #exemplo de sequencia de numeros

.text
main:
    la t0, numeros #carrega o endereço da sequencia
    lw t1, 0(t0)   #carrega o primeiro numero numero
    li t3, 20       #define o tamanho sa sequencia (5 numeros)

    loop:    
        addi t0, t0, 4      #avança para o próximo número da sequencia
        lw t2, 0(t0)        #carrega o próximo número
        
        bge t1, t2, skip     #pula se o prmieiro numero for maior ou igual ao próximo
        mv t1, t2          #caso contrario, atualiza o maior numero

    skip:
        addi t3, t3, -1     #decrementa o contador de iterações
        bnez t3, loop       #repete o loop até que todos os números sejam verificados

    Imprimir:
        addi a0, x0, 1      #argumento para o ecall executar
        addi a1, t1, 0      #argumento para ecall, o valor a ser
        ecall               #imprime o ecall inteiro

        li a0, 11 #11 quebra a linha
        li a1, 13 #corresponde ao \n
        ecall #imprime uma e quebra a linha para imprimir a próxima
    fim:
        li a0, 10
        ecall       #encerra o programa
        ret