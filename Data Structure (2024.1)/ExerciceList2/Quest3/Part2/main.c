#include "DinamEspecifQueue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Queue *queue = createQueue();
  if (queue) {
    int option, value, dequeuedValue;
    do {
      printf("\n0-Sair\n1-Enfileirar\n2-Desenfileirar\n3-Imprimir "
             "fila\n4-Obter primeiro elemento\n5-Obter último "
             "elemento\n6-Número de elementos\n");
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
        if (queue->start) {
          printf("Imprimindo fila...\n");
          printQueue(queue);
        } else {
          printf("Fila vazia!!\n");
        }
        break;
      case 4:
        if (queue) {
          printf("Primeiro elemento: %d\n", queue->start->data);
        } else {
          printf("Fila vazia!!\n");
        }
        break;
      case 5:
        if (queue) {
          printf("Último elemento: %d\n", queue->end->data);
        } else {
          printf("Fila vazia!!\n");
        }
        break;
      case 6:
        if (queue->start) {
          printf("Número de elementos da fila: %d\n", queue->size);
        } else {
          printf("Fila vazia!!\n");
        }
        break;
      default:
        if (option != 0) {
          printf("Opção inválida\n");
        }
      }
    } while (option != 0);

    // Libera a memória alocada para os nós da fila
    free(queue); // Libera a memória alocada para a fila
  }

  return 0;
}
