#include <stdio.h>
#include <stdlib.h>

int main(void){
float num1, num2, result;
char op;

printf("\n Digite o 1º número: ");
  scanf("%f", &num1);

printf("\n Digite o 2º número: ");
 scanf("%f", &num2);

printf("Qual operação deseja realizar (+,-,/ ou *)? ");
 scanf(" %c", &op);

    switch (op) {
        case '+':
            printf("Resultado: %.2f\n", num1+num2);
            break;

        case '-':
            printf("Resultado: %.2f\n", num1-num2);
            break;

        case '/':
            if (num2 != 0) {
                printf("Resultado: %.2f\n", num1/num2);
            } else {
                printf("Erro: Divisão por zero\n");
            }
            break;

        case '*':
            printf("Resultado: %.2f\n", num1*num2);
            break;
        default:
            printf("Operação inválida!\n");
    }



}
