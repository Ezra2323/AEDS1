#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include "util.h"
#include "fila.h"


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

void ImprimirPilha(TPilha *Pilha);

void LiberarPilha(TPilha *Pilha);

int PesquisarPilha(TPilha *Pilha, TProduto *x);

void a_InverterPilha(TPilha *Pilha);


void b_InverterPilha(TPilha *Pilha);


void c_InverterPilha(TPilha *Pilha);


#endif //PILHA_H_INCLUDED
