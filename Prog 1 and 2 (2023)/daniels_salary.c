#include <stdio.h>
#include <stdlib.h>

int main() {
    int minutos, horas,x;
    float valor;
    printf("\nDigite as horas: ");
        scanf("%d", &horas);

    printf("Digite os minutos: ");
        scanf("%d", &minutos);

    printf("Digite o valor por hora: ");
        scanf("%d", &x);

    horas=horas+minutos/60;
    minutos = minutos % 60;
        printf("\nTotal em horas e minutos: %d:%d\n", horas, minutos);

    valor=((float)(horas)+(float)(minutos)/60)*x;
    printf("\nValor a ser pago: R$%.2f", valor);

    return 0;
}
