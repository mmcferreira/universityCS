#include<stdio.h>
#include<stdlib.h>
#include "StackDinamEspec.h"

int main(){
  Stack *stack = createStack(); // Cria a pilha apenas uma vez

  int option;
  int num;
  int PopNum;
  do{
    printf("\n0-Exit\n1-Push\n2-Pop\n3-Number of elements\n4-Print stack\n");
    scanf("%d",&option);
    switch(option){
      case 1:
        printf("Insira o valor a ser empilhado:\n");
        scanf("%d",&num);
        push(stack,num);
        break;
      case 2:
        printf("Desempilhando...\n");
        PopNum = pop(stack);
        if(PopNum != -1){
          printf("Valor desempilhado:%d\n",PopNum);
        }
        else{
          printf("N�o h� valores na pilha\n");
        }
        break;
      case 3:
        printf("N�mero de elementos na pilha:%d\n",stack->size);
        break;
      case 4:
        if(stack && stack->top){
          printf("Imprimindo pilha...\n");
          printStack(stack);
        }
        else{
          printf("Pilha vazia!!\n");
        }
        break;
      default:
        if(option!=0){
          printf("Op��o inv�lida\n");
        }
    }
  }while(option!=0);

  free(stack); // Libera a mem�ria alocada para a pilha

  return 0;
}
