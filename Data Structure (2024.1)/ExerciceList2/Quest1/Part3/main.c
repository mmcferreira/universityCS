#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  HeadStack *head = createStack();

  int *number;
  int option;

  do {
    printf("\n\n --- ESCOLHA UMA DAS OPCOES ----\n");
    printf("1: Inserir elemento na pilha\n");
    printf("2: Remover elemento da pilha\n");
    printf("3: Mostrar o último elemento da pilha\n");
    printf("4: Mostrar quantos elementos tem na pilha\n");
    printf("5: Mostrar a pilha\n");
    printf("6: Liberar pilha\n");
    printf("7: SAIR\n");
    printf("\nEscolha uma das opções: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      printf("\nEscolha um elemento para inserir: ");
      number = (int *)malloc(sizeof(int));
      scanf("%d", number);
      push(head, number);
      printf("\nInserido\n");
      break;
    case 2:
      number = (int *)pop(head);
      if (number) {
        printf("\nElemento removido %d\n", *number);
        free(number);
      } else {
        printf("\nPilha vazia\n");
      }
      break;
    case 3:
      number = (int *)elementTop(head);
      if (number) {
        printf("\nO elemento do topo é %d\n", *number);
      } else {
        printf("\nPilha vazia\n");
      }
      break;
    case 4:
      printf("\nQuantidade de elementos na pilha: %d\n", totalElements(head));
      break;
    case 5:
      printStack(head);
      break;
    case 6:
      freeStack(head);
      printf("\nPilha liberada\n");
      exit(1);
      break;
    case 7:
      exit(1);
      break;
    default:
      printf("\nEscolha uma opção válida");
      break;
    }
  } while (option != 7);

  return 0;
}