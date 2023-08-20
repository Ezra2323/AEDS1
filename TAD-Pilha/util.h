
#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct produto
{
    int codigo;
    char nome[50];
    int QTD;
    float preco;
    char descricao[100];
} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula* prox;
} TCelula;

void LerProduto(TProduto *x);
void ImprimirProduto(TProduto x);

#endif // UTIL_H_INCLUDED
