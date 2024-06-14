#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue == NULL) {
    printf("Erro: Falha na alocação de memória.\n");
    exit(1);
  }
  queue->front = queue->rear = NULL;
  queue->size = 0;
  return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue *queue) { return queue->size == 0; }

// Função para enfileirar um elemento
void enqueue(Queue *queue, void *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Erro: Falha na alocação de memória.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  if (isEmpty(queue)) {
    queue->front = queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
  queue->size++;
}

// Função para desenfileirar um elemento
void *dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Erro: A fila está vazia.\n");
    exit(1);
  }
  Node *temp = queue->front;
  void *data = temp->data;
  queue->front = queue->front->next;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }
  free(temp);
  queue->size--;
  return data;
}

// Função para retornar o tamanho da fila
int size(Queue *queue) { return queue->size; }

// Função para imprimir a fila
void printQueue(Queue *queue) {
  Node *current = queue->front;
  while (current != NULL) {
    printf("%d ", *((int *)current->data));
    current = current->next;
  }
}

// Função para liberar a memória ocupada pela fila
void destroyQueue(Queue *queue) {
  while (!isEmpty(queue)) {
    dequeue(queue);
  }
  free(queue);
}
