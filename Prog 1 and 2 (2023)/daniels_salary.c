#include <stdio.h>
#include <stdlib.h>

int main() {
    int minutes, horas,val_hora;
    float valor;
    printf("\nDigite as horas: ");
        scanf("%d", &horas);

    printf("Digite os minutos: ");
        scanf("%d", &minutes);

    printf("Digite o valor por hora: ");
        scanf("%d", &val_hora);

    horas=horas+minutes/60;
    minutes = minutes % 60;
        printf("\nTotal em horas e minutos: %d:%d\n", horas, minutos);

    valor=((float)(horas)+(float)(minutes)/60)*val_hora;
        printf("\n O valor a ser pago: R$%.2f", valor);

    return 0;
}
