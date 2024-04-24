#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vetConjunto stConjunto; 

stConjunto *bubbleSort(stConjunto *conjunto);
void mostrarConj (stConjunto *conj);
void liberarConj(stConjunto *limpar);

stConjunto *criarConj();
stConjunto *inserirElem(stConjunto *conj, int elemIns);
stConjunto *removerElem(stConjunto *conj, int elemRem);

bool procElem (stConjunto *conj, int elem);
int maiorElem (stConjunto *conj);
int menorElem (stConjunto *conj);

stConjunto *intersec(stConjunto *conj1, stConjunto *conj2);
stConjunto *uniao (stConjunto *conj1, stConjunto *conj2);
stConjunto *diferenca(stConjunto *conj1, stConjunto *conj2);
bool igualdade (stConjunto *conj1, stConjunto *conj2);