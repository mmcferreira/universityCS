#include<stdio.h>
#include<stdlib.h>
#include "StackDinamEspec.h"

Stack* createStack(){
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if(stack){
    stack->top = NULL; // Inicializa o topo como NULL
    stack->size = 0;
    return stack;
  }
  else{
    printf("Erro ao criar pilha...\n");
    return NULL;
  }
}

void push(Stack *stack, int value){
  Node* elem = (Node*)malloc(sizeof(Node));
  if(elem){
    elem->data = value;
    elem->next = stack->top;
    stack->top = elem;
    stack->size++;
  }
  else{
    printf("Erro ao criar n�...\n");
  }
}

int pop(Stack* stack){
  int PopValue = -1; // Valor padrao para o caso de pilha vazia
  if(stack && stack->top){ // Verifica se a pilha e valida e nao esta vazia
    Node* aux = stack->top;
    PopValue = aux->data;
    stack->top = aux->next;
    stack->size--;
    free(aux);
  }
  return PopValue;
}

void printStack(Stack *stack){
  Node* aux = stack->top;
  while(aux){
    printf("%d ", aux->data);
    aux = aux->next;
  }
  printf("\n");
}

