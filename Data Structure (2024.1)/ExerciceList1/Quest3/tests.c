#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>

void geraVetor(long long int vet[50000]) {
    int i;
    for (i = 0; i < 50000; i++) {
        vet[i] = rand() % 500;
    }
}

void imprimeVetor(long long int vet[50000]) {
    int i;
    for (i = 0; i < 50000; i++) {
        printf("%3lld ", vet[i]);
    }
}

void copy(long long int vet1[50000], long long int vet2[50000]) {
    int i;
    for (i = 0; i < 50000; i++) {
        vet2[i] = vet1[i];
    }
}

void bubbleSort(long long int vet[50000]) {
    long long int i, j, aux, atrib = 0, comp = 0;
    for (i = 0; i < 50000; i++) {
        for (j = 0; j < 49999; j++) {
            if (vet[j] > vet[j + 1]) {
            comp++;
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                atrib += 3;
            }
        }
    }
    printf("\nNúmero total de atribuições  : %lld", atrib);
    printf("\nNúmero total de comparações  : %lld\n", comp);
}

void insertionSort(long long int vet[50000]) {
    long long int i, j, aux = 0, atrib = 0, comp = 0;
    for (i = 1; i < 50000; i++) {
        j = i;
        atrib++;
        while (j > 0 && vet[j] < vet[j - 1]) {
        comp++;
            aux = vet[j];
            vet[j] = vet[j - 1];
            vet[j - 1] = aux;
            j--;
            atrib += 3;
           
        }
    }
    printf("\nNúmero do total de atribuições  : %lld", atrib);
    printf("\nNúmero do total de comparações  : %lld\n", comp);
}

void selectionSort(long long int vet[50000]) {
    int i, j, minIndex, temp, atrib = 0, comp = 0;
    for (i = 0; i < 50000 - 1; i++) {
        minIndex = i;
        atrib++;
        for (j = i + 1; j < 50000; j++) {
        comp++;
            if (vet[j] < vet[minIndex]) {
                minIndex = j;
                atrib++;
               
            }
        }
        if (minIndex != i) {
        comp++;
            temp = vet[i];
            vet[i] = vet[minIndex];
            vet[minIndex] = temp;
            atrib += 3;
        }
    }
    printf("\nNúmero total de atribuições  : %d", atrib);
    printf("\nNúmero total de comparações  : %d\n", comp);
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    long long int bubble[50000], selection[50000], insertion[50000];
    clock_t comeco, fim;
    double cpu_time_used;
    geraVetor(bubble);
    copy(bubble, insertion);
    copy(bubble, selection);

    comeco = clock();
    bubbleSort(bubble);
    fim = clock();
    cpu_time_used = ((double)(fim - comeco)) / CLOCKS_PER_SEC;
    printf("\nBubble sort: %f segundos\n\n", cpu_time_used);

    printf("\n\n");
    comeco = clock();
    insertionSort(insertion);
    fim = clock();
    cpu_time_used = ((double)(fim - comeco)) / CLOCKS_PER_SEC;
    printf("\nInsertion sort: %f segundos\n\n", cpu_time_used);

    printf("\n\n");
    comeco = clock();
    selectionSort(selection);
    fim = clock();
    cpu_time_used = ((double)(fim - comeco)) / CLOCKS_PER_SEC;
    printf("\nSelection sort: %f segundos\n\n", cpu_time_used);

    return 0;
}
