/* agenda.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* função getch */
#ifdef DOS
#include <conio.h>
#else
#include <curses.h>
#endif
1
typedef struct agenda
{
char nome[40];
char email[40];
int telefone;
} AGENDA;
0 void aloca( AGENDA **pAgenda, int *piEntradas );
void consulta( AGENDA *pAgenda, int iEntradas);
void qs_ordena(AGENDA pAgenda[], int left, int right );
void ordena( AGENDA pAgenda[], int iEntradas );

void excluir(AGENDA **pAgenda, int *piEntradas);
void pesquisar(AGENDA *pAgenda, int iEntradas);
void alterar(AGENDA *pAgenda, int iEntradas);
0 int main(void)
{
AGENDA * pAgenda;

int iEntradas, op;
iEntradas=0;
40
pAgenda = (AGENDA *) malloc(sizeof(AGENDA)); /* alocando espaço para a posição 0
 do vetor */
if( pAgenda == NULL )
{
printf("\nErro de alocacao de memoria.");
exit(1);
}
do
{
flush(stdin);
printf("\n1 - Inclusao");
printf("\n2 - Alteracao");
printf("\n3 - Consulta");
printf("\n4 - Excluir");
printf("\n5 - Pesquisar");
printf("\n9 - Sair");
printf("\nEntre com uma opcao -> ");
scanf("%d", &op);