#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

int main(void)
{
    AGENDA *pAgenda;
    int iEntradas, opcao;
    iEntradas = 0;

    pAgenda = (AGENDA*)malloc(sizeof(AGENDA));  //aloca espaço para poosição 0 do vetor de estrutura AGENDA
        if(pAgenda == NULL)
        {
            printf ("\nErro de alocacao de memoria.");
            exit(1);
        } 

        do
        {
            fflush(stdin);
            printf("\n1 - Incluir");
            printf("\n2 - Alterar");
            printf("\n3 - Consultar");
            printf("\n4 - Exlcuir");
            printf("\n5 - Pesquisar");
            printf("\n9 - Sair");
            printf("\n Entre com uma das opcoes -> ");
            scanf("%d", &opcao);
            
            if(opcao == 1)
            {
                fflush(stdin);
                aloca(&pAgenda, &iEntradas);
                printf("*** Incluir ***");
                printf("\nEntre com o Nome:");
                gets(((pAgenda)->nome));
                fflush(stdin);
                
                printf("Entre com o telefone:");
                scanf("%d", &pAgenda[iEntradas].telefone);
                fflush(stdin);

                iEntradas++;
            }

            else if(opcao == 2)
            {
                alterar(pAgenda, iEntradas);
            }

            else if(opcao == 3)
            {
                ordena(pAgenda, iEntradas);
                consulta(pAgenda, iEntradas);
            }
            
            else if(opcao == 4)
            {
                ordena (pAgenda, iEntradas);
                excluir (pAgenda, iEntradas);
            }

            else if(opcao == 5)
            {
                ordena(pAgenda, iEntradas);
                pesquisar(pAgenda, iEntradas);
            }
        }

        while(opcao!=9);
}
