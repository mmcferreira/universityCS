#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

typedef struct agenda
{
    char nome[40];
    char email[40];
    int telefone;
}AGENDA;

void aloca(AGENDA **pAgenda, int *piEntradas)
{
    *pAgenda = (AGENDA *)realloc(*pAgenda, (*piEntradas + 1) * sizeof(AGENDA));
    if (*pAgenda == NULL){
        printf("\nErro de re-alocacao de memoria");
        exit(1);
    }
}

void consulta(AGENDA *pAgenda, int iEntradas)
{
	int i;
    for (i = 0; i < iEntradas; i++) {
        printf("\nRegistro %d", i);
        printf("\nNome: %s", pAgenda[i].nome);
        printf("\nEmail: %s", pAgenda[i].email);
        printf("\nTelefone: %d", pAgenda[i].telefone);
    }
}

void quicksort(AGENDA *pAgenda, int inicio, int fim)
{
    if (inicio < fim) {
        char *pivo = pAgenda[fim].nome;
        int i = inicio - 1;
        
        for (int j = inicio; j <= fim - 1; j++)
        {
            if (strcmp(pAgenda[j].nome, pivo) < 0)
            {
                i++;
    
                AGENDA temp = pAgenda[i];
                pAgenda[i] = pAgenda[j];
                pAgenda[j] = temp;
            }
        }
        
        AGENDA temp = pAgenda[i + 1];
        pAgenda[i + 1] = pAgenda[fim];
        pAgenda[fim] = temp;

        quicksort(pAgenda, inicio, i);      // sub-ilsta à esquerda do pivô
        quicksort(pAgenda, i + 2, fim);      // Sub-lista à direita do pivô
    }
}

void ordena(AGENDA *pAgenda, int iEntradas) {
    quicksort(pAgenda, 0, iEntradas - 1);
}

void excluir(AGENDA **pAgenda, int *piEntradas, int index) {
    if (index < *piEntradas) {
        (*pAgenda)[index] = (*pAgenda)[(*piEntradas) - 1];
        (*piEntradas)--;
        aloca(pAgenda, piEntradas);
    } else {
        printf("\nRegistro nao encontrado");
    }
}

void pesquisar(AGENDA *pAgenda, int iEntradas, char *nome){
	int i;
    for (i = 0; i < iEntradas; i++) {
        if (strcmp(pAgenda[i].nome, nome) == 0) {
            printf("\nRegistro %d", i);
            printf("\nNome : %s", pAgenda[i].nome);
            printf("\nEmail : %s", pAgenda[i].email);
            printf("\nTelefone : %d", pAgenda[i].telefone);
            return;
        }
    }
    printf("\nRegistro nao encontrado");
}

void alterar(AGENDA *pAgenda, int iEntradas, char *nome, char *novoNome, char *novoEmail, int novoTelefone) {
	int i ;
    for (i = 0; i < iEntradas; i++) {
        if (strcmp(pAgenda[i].nome, nome) == 0) {
            strcpy(pAgenda[i].nome, novoNome);
            strcpy(pAgenda[i].email, novoEmail);
            pAgenda[i].telefone = novoTelefone;
            return;
        }
    }
    printf("\nRegistro nao encontrado");
}
