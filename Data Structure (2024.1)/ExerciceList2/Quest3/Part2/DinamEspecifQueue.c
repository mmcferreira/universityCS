#include "DinamEspecifQueue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue) {
    queue->start = NULL;
    queue->end = NULL;
    queue->size = 0;
    return queue;
  } else {
    printf("Erro ao criar fila...\n");
    return NULL;
  }
}

void enqueue(Queue *queue, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode) {
    newNode->data = value;
    newNode->next = NULL;
    if (queue->end) {
      queue->end->next = newNode;
    }
    queue->end = newNode;
    if (!queue->start) {
      queue->start = newNode;
    }
    queue->size++;
  } else {
    printf("Erro ao alocar memória para o novo nó...\n");
  }
}

int dequeue(Queue *queue) {
  if (queue->start) {
    Node *temp = queue->start;
    int value = temp->data;
    queue->start = queue->start->next;
    if (!queue->start) {
      queue->end = NULL;
    }
    free(temp);
    queue->size--;
    return value;
  } else {
    printf("Fila vazia!\n");
    return -1; // Valor indicativo de erro
  }
}

void printQueue(Queue *queue) {
  Node *aux = queue->start;
  if (aux == NULL) {
    printf("Fila vazia!\n");
    return;
  }
  while (aux->next) {
    printf("%d -> ", aux->data);
    aux = aux->next;
  }
  printf("%d\n", aux->data);
}