#include <stdio.h>
#include <stdlib.h>
#include "OrderedList.h"

// Função para inicializar a lista
OrderedList* createOrderedList() {
    OrderedList *list = (OrderedList*)malloc(sizeof(OrderedList));
    if (list == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Função para verificar se a lista está vazia
int isOrderedListEmpty(OrderedList *list) {
    return list->size == 0;
}

// Função para inserir um elemento na lista
void insert(OrderedList *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isOrderedListEmpty(list) || *((int*)list->head->data) >= *((int*)data)) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL && *((int*)current->next->data) < *((int*)data)) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// Função para imprimir a lista
void printOrderedList(OrderedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", *((int*)current->data));
        current = current->next;
    }
    printf("\n");
}

// Função para liberar a memória ocupada pela lista
void destroyOrderedList(OrderedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    free(list);
}
