#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"


void PVazia(TPilha *Pilha)
{
    Pilha->topo = (TCelula *) malloc(sizeof(TCelula));
    Pilha->fundo = Pilha -> topo;
    Pilha->topo->prox= NULL;
    Pilha->tamanho = 0;
}
int FPVazia(TPilha Pilha)
{
    return(Pilha.topo == Pilha.fundo);
}



void Empilhar(TProduto x, TPilha *Pilha)
{
    TCelula* Aux;
    Aux = (TCelula *) malloc(sizeof(TCelula));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo =Aux;
    Pilha->tamanho++;
}



void Desempilhar(TPilha *Pilha, TProduto *Item)
{
    TCelula *y;

    if (FPVazia(*Pilha))
    {
        Pilha->fundo = y;
        return;
    }

    y = Pilha->topo;
    Pilha->topo = y->prox;
    *Item = y->prox->item;
    free(y);
    Pilha->tamanho--;
}



void ImprimirPilha(TPilha *Pilha)
{
    TProduto x;
    TPilha PAux;

    while(!FPVazia(*Pilha))
    {
        Desempilhar(Pilha,&x);
        ImprimirProduto(x);
        Empilhar(x,&PAux);
    }
    while(!FPVazia(PAux))
    {
        Desempilhar(&PAux, &x);
        Empilhar(x,Pilha);
    }
    free(Pilha->topo);
}

void LiberarPilha(TPilha *Pilha){

    TProduto x;
    while (!FPVazia(*Pilha))
    {
        Desempilhar(Pilha, &x);
    }

    free(Pilha->topo);

}


int PesquisarPilha(TPilha *Pilha, TProduto *x)
{
    TProduto y;
    TPilha Aux;
    int flag = 0;
    PVazia(&Aux);

    while(!FPVazia(*Pilha))
    {
        Desempilhar(Pilha,&y);
        if(strcmp(x->nome, y.nome) == 0)
        {
            *x=y;
            flag = 1;
        }
        Empilhar(y, &Aux);
    }

    while(!FPVazia(Aux))
    {
        Desempilhar(&Aux, &y);
        Empilhar(y, Pilha);
    }
    LiberarPilha(&Aux);

    if(flag == 1)
    {
        return 1;
    }

    if(flag == 0)
    {
        x->codigo = -1;
        return 0;
    }


}



void a_InverterPilha(TPilha *Pilha)
{
    TProduto x;
    TFila fila;
    FLVazia(&fila);


    //a) inverter uma pilha com uma fila
    while(!FPVazia(*Pilha))
    {
        Desempilhar(Pilha,&x);
        Enfileirar(x, &fila);

    }

    while(!FVazia(fila))
    {
        Desenfileirar(&fila, &x);
        Empilhar(x, Pilha);
    }
    LiberarFila(&fila);
}

void b_InverterPilha(TPilha *Pilha)
{
    TProduto x;
    TPilha Pilha_aux;
    PVazia(&Pilha_aux);


    //b) inverter uma pilha com uma pilha auxiliar
    while(!FPVazia(*Pilha))
    {
        Desempilhar(Pilha, &x);
        Empilhar(x, &Pilha_aux);
    }
    while(!FPVazia(Pilha_aux))
    {
        Desempilhar(&x, &Pilha_aux);
        Empilhar(x, Pilha);
    }
    LiberarPilha(&Pilha_aux);

}


void c_InverterPilha(TPilha *Pilha)
{
    TProduto x;
    TPilha Pilha2,Pilha3;
    PVazia(&Pilha2);
    PVazia(&Pilha3);


//c) inverter uma pilha com duas pilhas
    while(!FPVazia(*Pilha))
    {
        Desempilhar(Pilha, &x);
        Empilhar(x, &Pilha2);
    }
    while(!FPVazia(Pilha2))
    {
        Desempilhar(&Pilha2,&x );
        Empilhar(x, &Pilha3);
    }
    while(!FPVazia(Pilha3))
    {
        Desempilhar(&x, &Pilha3);
        Empilhar(x, Pilha);
    }
    LiberarPilha(&Pilha2);
    LiberarPilha(&Pilha3);

}

