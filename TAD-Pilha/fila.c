#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void FLVazia(TFila *fila)
{
    fila->frente = (TCelula *) malloc(sizeof(TCelula));
    fila->tras = fila->frente;
    fila->frente-> prox= NULL;
    fila->tamanho = 0;
}

int FVazia(TFila fila)
{
    return(fila.frente == fila.tras);
}

void Enfileirar(TProduto x, TFila *fila)
{
    fila->tras->prox = (TCelula *)malloc(sizeof(TCelula));
    fila->tras= fila->tras->prox;
    fila->tras->item = x;
    fila->tras->prox = NULL;
    fila->tamanho++;
}

void Desenfileirar(TFila *fila, TProduto *Item)
{
    TCelula* Aux1;
    if(!FVazia(*fila))
    {
        Aux1 =fila->frente->prox;
        fila->frente->prox = Aux1->prox;
        *Item = Aux1->item;

        free(Aux1);
        if (Aux1->prox == NULL)
            fila->tras = fila->frente;
        fila->tamanho--;
    }
    else
    {
        Item->codigo = -1;
    }
}


void ImprimirFila(TFila *fila)
{
    TFila Faux;
    TProduto x;
    FLVazia(&Faux);

    while(!FVazia(*fila))
    {
        Desenfileirar(fila,&x);
        ImprimirProduto(x);
        Enfileirar(x, &Faux);
    }

    while(!FVazia(Faux))
    {
        Desenfileirar(&Faux,&x);
        Enfileirar(x,fila);
    }

    free(Faux.frente);
}

int FPesquisar(TFila *fila, TProduto *x)
{
    TProduto y;
    TFila Faux;
    int flag =0;

    int tamanho = fila->tamanho;
    for(int i=0; i<tamanho; i++)
    {
        Desenfileirar(fila, &y);
        if (strcmp(y.nome, x->nome)==0)
        {
            *x= y;
            flag=1; // Fila vazia, o produto foi encontrado

        }
        Enfileirar(y,&Faux);
    }

    for(int i=0; i<tamanho; i++)
    {
        Desenfileirar(&Faux, &y);
        Enfileirar(y,fila);
    }

    if(flag == 1)
    {
        return 1;
    }
    else
    {
        x->codigo = -1;
        return 0;
    }
}



void FLiberar(TFila *fila)
{
    TProduto x;
    TCelula *Aux1, *Aux2;

    while (!FVazia(*fila))
    {
        Aux1 = fila->frente;
        Desenfileirar(fila, &x);

        while (Aux1 != NULL)
        {
            Aux2 = Aux1->prox;
            free(Aux1);
            Aux1 = Aux2;
        }
    }
}

void CopiarFila(TFila *fila_original)
{
    TFila *fila_auxiliar;
    TProduto x;
    FLVazia(&fila_original);

    while(!FVazia(*fila_original))
    {
        Desenfileirar(fila_original, &x);
        Enfileirar(x, fila_auxiliar);
        Enfileirar(x, fila_original);
    }

}

void InverterFila(TFila *fila_original)
{
    TProduto x,y;
    TFila fila_auxiliar;
    FLVazia(&fila_auxiliar);
    int n, m;
    n = fila_original->tamanho;

    for(int i=0; i<n; i++ )
    {

        m = fila_original->tamanho;
        for(i=0; i <m-1; i++)
        {
            Desenfileirar(fila_original, &y);
            Enfileirar(y, &fila_auxiliar);
        }

        Desenfileirar(fila_original, &x);


        while(!FVazia(fila_auxiliar))
        {
            Desenfileirar(&fila_auxiliar, &y);
            Enfileirar(y,fila_original);
        }

        Enfileirar(x, &fila_auxiliar);

    }

}

void LiberarFila(TFila *Fila){
    TProduto x;

    if(FVazia(*Fila)){
        free(Fila->frente);
        return;
    }

    Desenfileirar(Fila,&x);
    LiberarFila(Fila);

}
