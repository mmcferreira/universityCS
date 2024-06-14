#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include<stdbool.h>

void preenche_vet(int vet[10])
{
    int i;
    for(i=0;i<10;i++)
    vet[i]=rand () % 100;
}

void bubbleSort(int vet[10])
{
    int i,j,aux,troca=0,itj=0,iti=0;
    bool trocou;
    for(i=0;i<10;i++)
    {
        iti++;
        trocou=false;
        for(j=0;j<9;j++)
        {
            itj++;
            if(vet[j]>vet[j+1])
            {
                aux=vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;
                troca ++;
                trocou=true;
            }
        }
        if(!trocou)
        break;
    }
    printf("\n\n");
    printf("\n Número de iterações externas:%d\n",iti);
    printf("\n Número de iterações internas:%d\n",itj);
    printf("\nNúmero de trocas:%d\n",troca);
    printf("\n\n");
}

void imprime_vet(int vet[10])
{
    int i;
    for(i=0;i<10;i++)
    printf("\t%2d",vet[i]);
}

int main(){
    int vet[10];
    srand(time(NULL));
    preenche_vet(vet);
    imprime_vet(vet);
    bubbleSort(vet);
    printf("\n\n");
    imprime_vet(vet);
    
    return 0;
}