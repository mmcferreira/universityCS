#include "conjuntos.h"

int main (void){
    stConjunto *conjuntoA = createConj();
    stConjunto *conjuntoB = createConj();

    inserirElem(conjuntoA, 1);
    inserirElem(conjuntoA, 2);
    inserirElem(conjuntoA, 3);

    inserirElem(conjuntoB, 3);
    inserirElem(conjuntoB, 2);
    inserirElem(conjuntoB, 1);

    mostrarConj(conjuntoA);
    printf("Maior numero de A: %d\n", maiorElem(conjuntoA));
    printf("Menor numero de A: %d\n", maiorElem(conjuntoA));

    mostrarConj(conjuntoB);
    printf("Maior numero de B: %d\n", maiorElem(conjuntoA));
    printf("Menor numero de B: %d\n", maiorElem(conjuntoA));

    stConjunto *intersecaoConjs = intersec(conjuntoA, conjuntoB);
    stConjunto *uniaoConjs = uniao(conjuntoA, conjuntoB);
    stConjunto *diferencaConjs = diferenca(conjuntoA, conjuntoB);
    
    printf("O elemento 3 pertence ao conjunto A?: %s\n", hasEl(conjuntoA, 3)? "true" : "false");
    printf("Os conjuntos sao iguais?: %s\n", igualdade(conjuntoA, conjuntoB)? "true" : "false");

    liberarConj(conjuntoA);
    liberarConj(conjuntoB);

}