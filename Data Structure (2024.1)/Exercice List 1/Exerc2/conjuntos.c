#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conjuntos.h"

typedef struct vetConjuntos
{
    int elemento[200];
    int tamanho;
} stConjunto;


stConjunto *criarConj()
{
    stConjunto *conj = (stConjunto *)malloc(sizeof(stConjunto));
    if (!conj)
        return NULL;
    conj->tamanho = 0;
    return conj;
}


stConjunto *bubbleSort(stConjunto *conj)
{
    int aux;
    bool troca;
    while (troca = true)
    {
        troca = false;
        for (int j = 0; j < conj->tamanho; j++)
        {
            if (conj->elemento[j] > conj->elemento[j + 1] && conj->elemento[j + 1])
            {
                aux = conj->elemento[j];
                conj->elemento[j] = conj->elemento[j + 1];
                conj->elemento[j + 1] = aux;
                troca = true;
                j = 0;
            }
        }
        if (troca == false)
        {
            break;
        }
    }

    return conj;
}


stConjunto *inserirElem(stConjunto *conj, int elemIns)
{
    conj->elemento[conj->tamanho]= elemIns;
    conj->tamanho++;
    return bubbleSort(conj);        //para ele já sair ordenado
}

stConjunto *removerElem(stConjunto *conj, int elemRem)
{
    stConjunto *conjRemovido;       //cria o conjunto sem o elemento
    conjRemovido = criarConj();
    for (int i = 0; i < conj->tamanho; i++)
    {
        if (conj->elemento[i] != elemRem)   //conjunto vai ser sem o elemento
            inserirElem(conjRemovido, conj->elemento[i]);
    }
    return conjRemovido;
}

bool procElem (stConjunto *conj, int elem)
{
    bool tem = false;
    for (int i = 0; i < conj->tamanho; i++)
    {
    if (conj->elemento[i] == elem)
        {
            tem = true;
            break;
        }
    }
    return tem;
}

int maiorElem (stConjunto *conj)
{   
    return conj->elemento[conj->tamanho-1];
}

int menorElem (stConjunto *conj)
{
    return conj->elemento[0];
}

stConjunto *intersec(stConjunto *conj1, stConjunto *conj2)
{
    stConjunto *conjIntersec = criarConj();
    int igual = 0;
    int maior = conj1->tamanho > conj2->tamanho ? 1 : 2;

    if (maior == 1)
    {
        for (int i = 0; i < conj1->tamanho; i++)
        {
            igual = 0; 
                for (int j = 0; j < conj2->tamanho; j++)
                {
                    igual = conj1->elemento[i] == conj2->elemento[j] ? 1 : 0;
                if (igual){
                    insert(intersec, conj1->elemento[i]); 
                    break;
                    }
                }
        }
    }
    else
    {
        for (int i = 0; i < conj2->tamanho; i++)
        {
            igual = 0;
                for (int j = 0; j < conj1->tamanho; j++)
                {
                    igual = conj2->elemento[i] == conj1->elemento[j] ? 1 : 0;
                if (igual){
                    insert(intersec, conj2->elemento[i]);
                    break;
                }
                }
        }
    }

    return intersec;
}

stConjunto *uniao (stConjunto *conj1, stConjunto *conj2)
{
    stConjunto *un = criarConj, *intersecao = intersec (conj1, conj2);
    int diferenca;
    int maior = conj1->tamanho > conj2->tamanho? 1:2;

    if (maior ==1)
    {
        for (int i = 0; i < conj1->tamanho; i++)
        {
            inserirElem(un, conj1->elemento[i]);
        }

        for (int i = 0; i < conj2->tamanho; i++)
        {
            diferenca = 0;
            for (int j = 0; j < intersecao->tamanho; j++)
            {
                diferenca = conj2->elemento[i] != intersecao->elemento[j]? 1 : 0;
                if(diferenca == 0) break; 
            }
            if (diferenca)
                intersec(un, conj2->elemento[i]);
        }
    }

    else
    {
        for (int i = 0; i < conj2->tamanho; i++)
        {
            inserirElem(un, conj2->elemento[i]);
        }
        for (int i = 0; i < conj1->tamanho; i++)
        {
            diferenca = 0;
            for (int j = 0; j < un->tamanho; j++)
            {
                 diferenca = conj1->elemento[i] != intersecao->elemento[j]? 1 : 0;
                if(diferenca == 0) break; 
            }
            if (diferenca)
                inserirElem(un, conj1->elemento[i]);
        }
    }

    return un;
}

stConjunto *diferenca(stConjunto *conj1, stConjunto *conj2)
{
    stConjunto *diff = createConj();
    int diferenca = 0;
        for (int i = 0; i < conj1->tamanho; i++)
        {
            diferenca = 0; 
                for (int j = 0; j < conj2->tamanho; j++)
                {
                    diferenca = conj1->elemento[i] != conj2->elemento[j] ? 1 : 0;
                     
                     if (!diferenca){
                        break;
                     }
                }
                     if(diferenca)
                        insert(diff, conj1->elemento[i]); 
               
    }
    return diff;
}

bool igualdade (stConjunto *conj1, stConjunto *conj2)
{
        bool ig = false;

    if(conj1->tamanho == conj2->tamanho){
        for(int i = 0; i<conj1->tamanho; i++){
           ig = conj1->elemento[i] == conj2->elemento[i]? true : false;
           if(ig == false){
            break;
           }
            return ig;
        }
    }else{
        return ig;
    }
}

void mostrarConj (stConjunto *conj)
{
    int i;
    printf("{");
    for (i = 0; i < conj->tamanho; i++)
    {
        if(i == conj->tamanho - 1)
        {
            printf("%d", conj->elemento[i]);
            break;
        }
        printf("%d, ", conj->elemento[i]);
    }
    printf("}\n");
}

void liberarConj(stConjunto *limpar)
{
    free(limpar);
}