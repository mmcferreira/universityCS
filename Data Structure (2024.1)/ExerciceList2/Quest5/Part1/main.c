#include "EspecificList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  List *list = createList();
  int option, value;
  do {
    printf("\n0-Sair\n1-Inserir\n2-Imprimir lista\n3-Obter primeiro "
           "elemento\n4-Obter último elemento\n5-Número de elementos\n");
    scanf("%d", &option);
    switch (option) {
    case 1:
      printf("Insira o valor a ser adicionado:\n");
      scanf("%d", &value);
      insertInList(list, value);
      break;
    case 2:
      if (list->startList) {
        printf("Imprimindo lista...\n");
        printList(list);
      } else {
        printf("Lista vazia!!\n");
      }
      break;
    case 3:
      if (list->startList) {
        printf("Primeiro elemento: %d\n", list->startList->data);
      } else {
        printf("Lista vazia!!\n");
      }
      break;
    case 4:
      if (list->endList) {
        printf("Último elemento: %d\n", list->endList->data);
      } else {
        printf("Lista vazia!!\n");
      }
      break;
    case 5:
      if (list) {
        printf("Quantidade de elementos na lista: %d\n", list->size);
      }
      break;
    default:
      if (option != 0) {
        printf("Opção inválida\n");
      }
    }
  } while (option != 0);

  freeList(list);

  return 0;
}
