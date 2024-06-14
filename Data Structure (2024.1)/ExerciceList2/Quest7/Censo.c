#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 50

typedef struct Node {
    char city[SIZE];
    int population;
    struct Node *next;    
} Node;

typedef struct Censo {
    Node *censo90s;
    Node *censo00s; 
} Censo;

Censo* createCenso() {
    Censo *censo = (Censo*)malloc(sizeof(Censo));
    if (censo) {
        censo->censo90s = NULL;
        censo->censo00s = NULL;
        return censo;
    } else {
        printf("Erro ao alocar memória...\n");
        return NULL;
    }
}

void insertData(Censo *censo, char city[SIZE], int population, int year) {
    if (!censo) {
        printf("Censo não foi criado corretamente.\n");
        return;
    }

    Node *newData = (Node*)malloc(sizeof(Node));
    if (newData) {
        strcpy(newData->city, city);
        newData->population = population;
        newData->next = NULL;

        Node **targetList = (year == 1990) ? &(censo->censo90s) : (year == 2000) ? &(censo->censo00s) : NULL;

        if (targetList) {
            if (*targetList == NULL || newData->population > (*targetList)->population) {
                newData->next = *targetList;
                *targetList = newData;
            } else {
                Node *aux = *targetList;
                while (aux->next && aux->next->population >= newData->population) {
                    aux = aux->next;
                }
                newData->next = aux->next;
                aux->next = newData;
            }
        } else {
            printf("Década inválida.\n");
            free(newData);
        }
    } else {
        printf("Erro ao alocar memória!!\n");
    }
}

void insertCityData(Censo *censo) {
    char city[SIZE];
    int population1990, population2000;

    printf("Informe o nome da cidade: ");
    scanf("%s", city);
    printf("População em 1990: ");
    scanf("%d", &population1990);
    insertData(censo, city, population1990, 1990);

    printf("População em 2000: ");
    scanf("%d", &population2000);
    insertData(censo, city, population2000, 2000);
}

void printCenso(Censo *censo) {
    Node *aux90s = censo->censo90s;
    Node *aux00s = censo->censo00s;

    printf("\n\t\tCenso das décadas 1990 e 2000:\n");
    printf("--------------------------------------------------------\n");
    printf("|   1990   |   População   |   2000   |   População   |\n");
    printf("--------------------------------------------------------\n");

    while (aux90s || aux00s) {
        if (aux90s) {
            printf("| %-8s | %-12d | ", aux90s->city, aux90s->population);
            aux90s = aux90s->next;
        } else {
            printf("| %-8s | %-12s | ", "", "");
        }

        if (aux00s) {
            printf("%-8s | %-12d |\n", aux00s->city, aux00s->population);
            aux00s = aux00s->next;
        } else {
            printf("%-8s | %-12s |\n", "", "");
        }
    }

    printf("--------------------------------------------------------\n");
}

int main() {
    Censo *censo = NULL;
    int option;

    censo = createCenso();
    do {
        printf("\n\t0 - sair\n\t1 - inserir dados\n\t2 - imprimir censo\n\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                insertCityData(censo);
                break;
            case 2:
                printf("\n\n");
                printCenso(censo);
                break;
            default:
                if (option != 0) {
                    printf("Opção inválida\n");
                }
        }
    } while (option != 0);

    return 0;
}
