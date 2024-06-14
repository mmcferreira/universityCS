#include "CircularVector.h"
#include <stdio.h>
#include <stdlib.h>

Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue) {
    queue->start = -1;
    queue->end = -1;
    queue->size = 0;
  } else {
    printf("Erro ao criar fila...\n");
  }
  return queue;
}

void enqueue(Queue *queue, int value) {
  if (queue->size == SIZE) {
    printf("Fila cheia!\n");
    return;
  }
  if (queue->start == -1) {
    queue->start = 0;
  }
  queue->end = (queue->end + 1) % SIZE;
  queue->data[queue->end] = value;
  queue->size++;
}

int dequeue(Queue *queue) {
  if (queue->size == 0) {
    printf("Fila vazia!\n");
    return -1; // Valor indicativo de erro
  }
  int value = queue->data[queue->start];
  queue->start = (queue->start + 1) % SIZE;
  queue->size--;
  if (queue->size == 0) {
    queue->start = -1;
    queue->end = -1;
  }
  return value;
}

void printQueue(Queue *queue) {
  if (queue->size == 0) {
    printf("Fila vazia!\n");
    return;
  }
  int i;
  for (i = 0; i < queue->size; i++) {
    int index = (queue->start + i) % SIZE;
    printf("%d -> ", queue->data[index]);
  }
  printf("NULL\n");
}

int getFront(Queue *queue) {
  if (queue->size == 0) {
    printf("Fila vazia!\n");
    return -1; // Valor indicativo de erro
  }
  return queue->data[queue->start];
}

int getRear(Queue *queue) {
  if (queue->size == 0) {
    printf("Fila vazia!\n");
    return -1; // Valor indicativo de erro
  }
  int rearIndex = (queue->start + queue->size - 1) % SIZE;
  return queue->data[rearIndex];
}
