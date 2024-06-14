#include "pilha.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

HeadStack *createStack() {
  HeadStack *head = (HeadStack *)malloc(sizeof(HeadStack));
  if (head) {
    head->count = 0;
    head->top = NULL;
  }
  return head;
}

int empty(HeadStack *head) { return (head->count == 0) ? 1 : 0; }

void push(HeadStack *head, void *data) {
  StackElements *newNode = (StackElements *)malloc(sizeof(StackElements));
  if (!newNode) {
    return;
  } else {
    newNode->data = data;
    newNode->link = head->top;
    head->top = newNode;
    head->count++;
  }
}

void *pop(HeadStack *head) {
  void *auxData;
  if (empty(head)) {
    auxData = NULL;
  } else {
    StackElements *aux = head->top;
    auxData = head->top->data;
    head->top = head->top->link;
    free(aux);
    head->count--;
  }
  return auxData;
}

void *elementTop(HeadStack *head) {
  if (empty(head)) {
    printf("\nPilha vazia\n");
    return NULL;
  } else {
    return head->top->data;
  }
}

// Função para retornar o total de elementos na pilha
int totalElements(HeadStack *head) { return head->count; }

// Função para liberar a pilha
HeadStack *freeStack(HeadStack *head) {
  if (head) {
    while (head->top != NULL) {
      free(head->top->data);
      StackElements *aux = head->top;
      head->top = head->top->link;
      free(aux);
    }
    free(head);
  }
  return NULL;
}

// Função para imprimir a pilha
void printStack(HeadStack *head) {
  if (empty(head)) {
    printf("\nPilha vazia\n");
    return;
  }

  printf("\nElementos da pilha:\n");
  StackElements *current = head->top;
  while (current != NULL) {
    printf("%d\n",
           *((int *)current->data)); // Assumindo que a pilha contém inteiros
    current = current->link;
  }
}