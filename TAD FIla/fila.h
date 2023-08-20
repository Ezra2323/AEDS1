#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


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
    struct celula *prox;
} TCelula;

typedef struct
{
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;
void FLVazia(TFila *fila);

int FVazia(TFila fila);

void Enfileirar(TProduto x, TFila *fila);

void ImprimirFila(TFila *fila);

int FPesquisar(TFila *fila, TProduto *x);

void LerProduto(TProduto *x);

void Desenfileirar(TFila *fila, TProduto *Item);

void ImprimirProduto(TProduto x);

void FLiberar(TFila *fila);

void CopiarFila(TFila *fila_original, TFila *fila_aux);

void InverterFila(TFila *fila);

#endif // FILA_H_INCLUDED
