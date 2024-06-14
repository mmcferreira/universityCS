#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct Queue {
  int data[SIZE];
  int start;
  int end;
  int size;
} Queue;

Queue *createQueue();

void enqueue(Queue *queue, int value);

int dequeue(Queue *queue);

void printQueue(Queue *queue);

int getFront(Queue *queue);

int getRear(Queue *queue);