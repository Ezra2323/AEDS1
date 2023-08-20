
#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct produto
{

    char nome[50];
    int linha;
    int coluna;
} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula* prox;
} TCelula;



#endif // UTIL_H_INCLUDED
