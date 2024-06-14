#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"



void aloca(AGENDA **pAgenda, int *piEntradas) {
    *pAgenda = (AGENDA *)realloc(*pAgenda, (*piEntradas + 1) * sizeof(AGENDA));
    if (*pAgenda == NULL) {
        printf("\nErro de re-alocacao de memoria");
        exit(1);
    }
}

void consulta(AGENDA *pAgenda, int iEntradas){
     int i;
	printf("\n consultas disponiveis \n\n");
    for (i = 0; i < iEntradas; i++) {
        printf("\nRegistro %d", i);
        printf("\nNome: %s", pAgenda[i].nome);
        printf("\nEmail: %s", pAgenda[i].email);
        printf("\nTelefone: %d", pAgenda[i].telefone);
     }
}


void pesquisar( AGENDA *pAgenda, int iEntradas){
  char nome[50],op;
  int i = 0;
  printf("Digite o nome do cliente para verificar se esta agendando: ");
  fgets(nome,50,stdin);
  verificacao_input(nome);
  for(i = 0; i< iEntradas;i++){
    int tamanho_string = strcmp(pAgenda[i].nome,nome); // funcao que compara duas strings caractere por caracter
    if(tamanho_string == 0){ 
      printf("\nConsulta encontrado\n");
      printf("\nNome do cliente: %s", pAgenda[i].nome);
      printf("\n email:  %s", pAgenda[i].email);
      printf("\ntelefone: %d\n", pAgenda[i].telefone);
      break;
    }
    else {
      printf("\nConsulta nao encontrado!\n");
    }
  }
}


void excluir( AGENDA **pAgenda, int *iEntradas){
  char nome[50],op;
  int i = 0;
  printf("Digite o nome do cliente que quer consultar: ");
  fgets(nome,50,stdin);
  verificacao_input(nome);
  for(i = 0; i< *iEntradas;i++){
    int tamanho_string = strcmp((*pAgenda)[i].nome,nome); 
    if(tamanho_string == 0){ 
      printf("\nConsulta encontrado\n");
      printf("\nNome : %s", (*pAgenda)[i].nome);
      printf("\nEmail:  %s", (*pAgenda)[i].email);
      printf("\nTelefone: %d\n", (*pAgenda)[i].telefone);
      printf("\nDeseja apagar? [s] ou [n]: ");
      scanf("%c", &op);

      if(op == 's' || op == 'S'){
        (*pAgenda)[i]= (*pAgenda)[(*iEntradas) - 1]; //copiando o ultimo elemento para a posicao penultima
        (*iEntradas)--;
        aloca(pAgenda,iEntradas); // realloca com a quantidade atual da agenda
      }
      break;
    }
    else {
      printf("\nConsulta nao encontrado!\n");
    }
  }
}

void bubbleSort(AGENDA ***pAgenda, int iEntradas) {
    int i, j;
    for (i = 0; i < iEntradas-1; i++) {     
        for (j = 0; j < iEntradas-i-1; j++) {
            if (strcmp((*pAgenda)[j]->nome, (*pAgenda)[j+1]->nome) > 0) {
                AGENDA *temp = (*pAgenda)[j];
                (*pAgenda)[j] = (*pAgenda)[j+1];
                (*pAgenda)[j+1] = temp;
            }
        }
    }
}

void ordena(AGENDA ***pAgenda, int iEntradas) {
    bubbleSort(pAgenda, iEntradas);
}

void verificacao_input(char *name){
 		if ((strlen(name)>0) && (name[strlen(name) - 1] == '\n')){ 
   		name[strlen(name) - 1] = '\0';
  }

}


void alterar(AGENDA *pAgenda, int iEntradas){
    char nome[50];
    int i = 0, encontrado = 0;
    printf("Digite o nome do cliente que quer alterar: ");
    fgets(nome,50,stdin);
    verificacao_input(nome);
    for(i = 0; i< iEntradas;i++){
        int tamanho_string = strcmp(pAgenda[i].nome,nome); 
        if(tamanho_string == 0){ 
            printf("\nNome encontrado\n");
            printf("\nNome: %s", pAgenda[i].nome);
            printf("\nEmail:  %s", pAgenda[i].email);
            printf("\nTelefone: %d\n", pAgenda[i].telefone);
            
            printf("\n*** Fazendo alteracao ***\n\n");
            printf("Digite o nome: ");
            fgets(pAgenda[i].nome,50,stdin);
            verificacao_input(pAgenda[i].nome);
            printf("Digite o email: ");
            fgets(pAgenda[i].email,50,stdin);
            verificacao_input(pAgenda[i].email);
            printf("Digite o telefone: ");
            scanf("%d", &pAgenda[i].telefone);
            getchar(); 

            encontrado = 1;
            break;
        }
    }
    if(!encontrado) {
        printf("\nNome nao encontrado!\n");
    }
}

