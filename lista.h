#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
typedef struct PProduto
{
    int codigo;
    char nome[50];
    int QTD;
    float preco;
    char descricao[100];
} Produto;

typedef struct celula
{
    Produto item;
    struct celula *prox;
} TCelula;

typedef struct
{
    TCelula *primeiro;
    TCelula *ultimo;
    int tamanho;
} TLista;

void LVazia(TLista *Lista);

int Vazia(TLista Lista);

void Inserir(Produto x, TLista *Lista);

void Imprimir(TLista Lista);

TCelula *Pesquisar(TLista Lista, Produto Item);

void LerProduto(Produto *x);

void Excluir(TLista *Lista, Produto *Item);

void ImprimirProduto(Produto x);

void LiberarLista(TLista *Lista);

#endif // LISTA_H_INCLUDED
