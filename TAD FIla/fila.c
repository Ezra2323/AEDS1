#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void FLVazia(TFila *fila)
{
    fila->frente = (TCelula *) malloc(sizeof(TCelula));
    fila->tras = fila -> frente;
    fila->frente -> prox= NULL;
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
    FLVazia(&Faux);
    int flag =0;

    while (!FVazia(*fila))
    {
        Desenfileirar(fila, &y);
        if (strcmp(y.nome, x->nome) == 0)
        {
            *x = y;
            flag = 1;
            break;
        }
        Enfileirar(y, &Faux);
    }

    while (!FVazia(Faux))
    {
        Desenfileirar(&Faux, &y);
        Enfileirar(y, fila);
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

void LerProduto(TProduto *x)
{
    printf("\nDigite o codigo: ");
    fflush(stdin);
    scanf("%d", &x->codigo);

    printf("\nDigite nome: ");
    fflush(stdin);
    fgets(x->nome, 50, stdin);

    printf("\nDigite a quantidade: ");
    fflush(stdin);
    scanf("%d", &x->QTD);

    printf("\nDigite a preco: ");
    fflush(stdin);
    scanf("%f", &x->preco);

    printf("\nDigite descricao: ");
    fflush(stdin);
    fgets(x->descricao, 100, stdin);
}

void Desenfileirar(TFila *fila, TProduto *Item)
{
    TCelula *Aux1;

    if (!FVazia(*fila))
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

void ImprimirProduto(TProduto x)
{
    printf("\n Codigo:%d", x.codigo);
    printf("\n Nome:%s", x.nome);
    printf("\n Quantidade:%d", x.QTD);
    printf("\n Preco:%f", x.preco);
    printf("\n Descricao:%s", x.descricao);
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

void CopiarFila(TFila *fila_original, TFila *fila_aux)
{

    TCelula *aux = fila_original->frente;

    while (aux != NULL) {
        Enfileirar(aux->item, fila_aux);
        aux = aux->prox;
    }
}

void InverterFila(TFila *fila)
{
    TProduto x,y;
    TFila fila_auxiliar;
    FLVazia(&fila_auxiliar);
    int n, m;
    n = fila->tamanho;

    for(int i=0; i<n; i++ )
    {

        m = fila->tamanho;
        for(i=0; i <m-1; i++)
        {
            Desenfileirar(fila, &y);
            Enfileirar(y, &fila_auxiliar);
        }

        Desenfileirar(fila, &x);


        while(!FVazia(fila_auxiliar)){
           Desenfileirar(&fila_auxiliar, &y);
           Enfileirar(y,fila);
        }

        Enfileirar(x, &fila_auxiliar);

    }


}
