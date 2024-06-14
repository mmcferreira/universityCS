#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Queue *queue = createQueue();

  // Exemplo de uso com inteiros
  printf("Enfileirando inteiros: \n");
  int i, num;
  for (i = 1; i <= 5; i++) {
    printf("Digite o %dº número inteiro: ", i);
    scanf("%d", &num);
    int *numPtr = (int *)malloc(
        sizeof(int)); // Aloca memória para cada novo número inteiro
    *numPtr = num;
    enqueue(queue, numPtr);
  }

  printf("\nTamanho da fila: %d\n", size(queue));
  printf("Desenfileirando inteiros: \n");
  while (!isEmpty(queue)) {
    printf("Fila: ");
    printQueue(queue);
    printf("\nDesenfileirando o número: %d\n", *((int *)dequeue(queue)));
  }

  printf("Fila vazia!\n");

  destroyQueue(queue);
  return 0;
}
