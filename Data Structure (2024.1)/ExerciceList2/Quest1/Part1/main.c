#include "CircularVector.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Queue *queue = createQueue();
  if (queue) {
    int option, value, dequeuedValue;
    do {
      printf("\n0-Exit\n1-Enfileirar\n2-Desenfileirar\n3-Escrever "
             "Fila\n4-Mostrar o Elemento Inicial "
             "\n5-Mostrar o Elemento Final\n");
      scanf("%d", &option);
      switch (option) {
      case 1:
        printf("Insira o valor a ser adicionado:\n");
        scanf("%d", &value);
        enqueue(queue, value);
        break;
      case 2:
        printf("Removendo da fila...\n");
        dequeuedValue = dequeue(queue);
        if (dequeuedValue != -1) {
          printf("Valor removido: %d\n", dequeuedValue);
        }
        break;
      case 3:
        printf("Imprimindo fila...\n");
        printQueue(queue);
        break;
      case 4:
        if (queue->start != -1) {
          printf("Primeiro elemento: %d\n", queue->start);
        } else {
          printf("Fila vazia...\n");
        }
        break;
      case 5:
        if (queue->start != -1) {
          printf("Ultimo elemento: %d\n", queue->end);
        } else {
          printf("Fila vazia...\n");
        }
        break;
      default:
        if (option != 0) {
          printf("Opcao invalida\n");
        }
      }
    } while (option != 0);

    free(queue); // Libera a mem�ria alocada para a fila
  }

  return 0;
}