#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Conj.h"

stConj *criarConj()
{
    stConj *conj = (stConj *)malloc(sizeof(stConj));
    if (!conj)
        return NULL;
    conj->tamanho = 0;
    return conj;
}