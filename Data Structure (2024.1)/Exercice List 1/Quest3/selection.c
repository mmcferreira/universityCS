#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
#include<time.h>

void preenche_vet(int vet[10])
{
    int i;
    for(i = 0; i < 10; i++)
     vet[i] = rand() % 10;
}

void selectionSort(int vet[10]){
    int i, j, aux;
    for(i = 0; i < 10; i++){
        aux = i;
        for(j = i + 1; j < 10; j++){
            if(vet[j] < vet[aux]){
                aux = j;
            }
        }
        int temp = vet[i];
        vet[i] = vet[aux];
        vet[aux] = temp;
    }
}

void imprime_vet(int vet[10]){
    int i;
    printf("\n\n");
    for(i = 0; i < 10; i++)
        printf("\t[%d]: %2.d\n", i, vet[i]);
}

int main(){
    int vet[10];
    srand(time(NULL));
    preenche_vet(vet);
    imprime_vet(vet);
    printf("\n\n");
    selectionSort(vet);
    imprime_vet(vet);

    return 0;
}
