#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
    char nome[100];
    char email[100];
    int telefone;
}AGENDA;

void aloca(AGENDA **pAgenda, int *piEntradas );
void consulta(AGENDA *pAgenda, int iEntradas);

void ordena(AGENDA *pAgenda[], int iEntradas );

void excluir(AGENDA **pAgenda, int *piEntradas);
void pesquisar(AGENDA *pAgenda, int iEntradas);
void alterar(AGENDA *pAgenda, int iEntradas);
