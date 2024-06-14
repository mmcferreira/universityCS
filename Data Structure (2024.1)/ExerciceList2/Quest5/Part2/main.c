#include <stdio.h>
#include <stdlib.h>
#include "OrderedList.h"

int main() {
    OrderedList *list = createOrderedList();

    // Exemplo de uso com inteiros
    printf("Inserindo inteiros na lista ordenada: \n");
    int i, num;
    for (i = 1; i <= 5; i++) {
        printf("Digite o %dº número inteiro: ", i);
        scanf("%d", &num);
        int *numPtr = (int*)malloc(sizeof(int)); // Aloca memória para cada novo número inteiro
        *numPtr = num;
        insert(list, numPtr);
    }

    printf("\nConteúdo da lista ordenada: ");
    printOrderedList(list);

    destroyOrderedList(list);
    return 0;
}
