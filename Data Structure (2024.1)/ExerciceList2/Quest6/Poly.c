#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct Node {
    int coef;
    int exp;
    struct Node *next;
} Node;

typedef struct Poly {
    Node *highestDegree;
    Node *lowestDegree;
    int sizePoly;
} Poly;

Poly* createPoly() {
    Poly *polyX = (Poly*)malloc(sizeof(Poly));
    if(polyX) {
        polyX->highestDegree = NULL;
        polyX->lowestDegree = NULL;
        polyX->sizePoly = 0;
        return polyX;
    } else {
        printf("Erro ao alocar memória!!\n");
        return NULL;
    }
}

void insertPoly(Poly *poly, int coef, int exp) {
    Node *term = (Node*)malloc(sizeof(Node));
    if(term) {
        term->coef = coef;
        term->exp = exp;
        if(!poly->highestDegree || exp > poly->highestDegree->exp) {
            term->next = poly->highestDegree;
            poly->highestDegree = term;
            if(poly->sizePoly == 0)
                poly->lowestDegree = term;
            poly->sizePoly++;
        } else {
            Node *aux = poly->highestDegree;
            while(aux->next && term->exp < aux->next->exp) {
                aux = aux->next;
            }
            term->next = aux->next;
            aux->next = term;
            if(aux == poly->lowestDegree)
                poly->lowestDegree = term;
            poly->sizePoly++;
        }
    } else {
        printf("Erro ao alocar memória...");
    }
}

void sumPoly(Poly *sum, Poly *poly1, Poly *poly2) {
    Node *aux1 = poly1->highestDegree;
    Node *aux2 = poly2->highestDegree;
    while(aux1 && aux2) {
        if(aux1->exp == aux2->exp) {
            insertPoly(sum, aux1->coef + aux2->coef, aux1->exp);
            aux1 = aux1->next;
            aux2 = aux2->next;
        } else if(aux1->exp > aux2->exp) {
            insertPoly(sum, aux1->coef, aux1->exp);
            aux1 = aux1->next;
        } else {
            insertPoly(sum, aux2->coef, aux2->exp);
            aux2 = aux2->next;
        }
    }
    while(aux1) {
        insertPoly(sum, aux1->coef, aux1->exp);
        aux1 = aux1->next;
    }
    while(aux2) {
        insertPoly(sum, aux2->coef, aux2->exp);
        aux2 = aux2->next;
    }
}

void printPoly(Poly *poly) {
    Node *current = poly->highestDegree;
    while(current) {
        printf("%dx^%d ", current->coef, current->exp);
        current = current->next;
    }
    printf("\n");
}

void clearPoly(Poly *poly) {
    Node *current = poly->highestDegree;
    Node *next;
    while(current) {
        next = current->next;
        free(current);
        current = next;
    }
    free(poly);
}

int main() {
    Poly *polyOne = createPoly();
    Poly *polyTwo = createPoly();
    Poly *sumPolyResult = createPoly(); // Renomeando a variável sum para evitar confusão
    int option;
    int coef, exp;

    do {
        printf("\n0-Sair\n1-Inserir termo no primeiro polinômio\n2-Inserir termo no segundo polinômio\n3-Somar Polinômios\n4-Imprimir Polinômios\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Digite o coeficiente e o expoente de algum termo do primeiro polinômio:\n");
                printf("Coeficiente: ");
                scanf("%d", &coef);
                printf("Expoente: ");
                scanf("%d", &exp);
                insertPoly(polyOne, coef, exp);
                break;

            case 2:
                printf("Digite o coeficiente e o expoente de algum termo do segundo polinômio:\n");
                printf("Coeficiente: ");
                scanf("%d", &coef);
                printf("Expoente: ");
                scanf("%d", &exp);
                insertPoly(polyTwo, coef, exp);
                break;

            case 3:
                printf("Somar Polinômios\n");
                sumPoly(sumPolyResult, polyOne, polyTwo);
                break;

            case 4:
                printf("Polinômio 1: ");
                printPoly(polyOne);
                printf("Polinômio 2: ");
                printPoly(polyTwo);
                printf("Soma: ");
                printPoly(sumPolyResult);
                break;

            default:
                if(option != 0)
                    printf("Opção inválida!\n");
                break;
        }
    } while(option != 0);

    clearPoly(polyOne);
    clearPoly(polyTwo);
    clearPoly(sumPolyResult);

    return 0;
}
