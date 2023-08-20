#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#include "util.h"


typedef struct fila
{
    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TFila;

void FLVazia(TFila *fila);
int FVazia(TFila fila);
void Enfileirar(TProduto x, TFila *fila);
void Desenfileirar(TFila *fila, TProduto *Item);
void ImprimirFila(TFila *fila);
int FPesquisar(TFila *fila, TProduto *x);
void LiberarFila(TFila *Fila);

#endif // FILA_H_INCLUDED

