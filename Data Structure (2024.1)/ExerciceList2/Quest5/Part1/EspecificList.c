#include "EspecificList.h"
#include <stdio.h>
#include <stdlib.h>

List *createList() {
  List *list = (List *)malloc(sizeof(List));
  if (list) {
    list->startList = NULL;
    list->endList = NULL;
    list->size = 0;
    return list;
  } else {
    printf("Erro ao criar lista...\n");
    return NULL;
  }
}

void insertInList(List *list, int value) {
  Node *newElement = (Node *)malloc(sizeof(Node));
  if (newElement) {
    newElement->data = value;
    newElement->next = NULL;

    if (list->startList == NULL || list->startList->data >= value) {
      newElement->next = list->startList;
      list->startList = newElement;
      if (list->endList == NULL) {
        list->endList = newElement;
      }
    } else {
      Node *aux = list->startList;
      while (aux->next != NULL && aux->next->data < value) {
        aux = aux->next;
      }
      newElement->next = aux->next;
      aux->next = newElement;
      if (newElement->next == NULL) {
        list->endList = newElement;
      }
    }
    list->size++;
  } else {
    printf("Erro ao alocar memória para o novo elemento...\n");
  }
}

void printList(List *list) {
  Node *aux = list->startList;
  if (aux == NULL) {
    printf("Lista vazia!\n");
    return;
  }
  while (aux->next) {
    printf("%d -> ", aux->data);
    aux = aux->next;
  }
  printf("%d\n", aux->data);
}

void freeList(List *list) {
  Node *current = list->startList;
  Node *next;
  while (current) {
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}
