#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include "util.h"

typedef struct
{
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void PVazia(TPilha *Pilha);

int FPVazia(TPilha Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *Item);

void LiberarPilha(TPilha *Pilha);

void preencherPilha(int linhas, int colunas, char matriz[linhas][colunas], TPilha *pilha);

void lerArquivoCaracterePorCaractere(TPilha *pilha);

void instrucoes();

#endif //PILHA_H_INCLUDED
