#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TLista *Lista){
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista -> tamanho = 0;
}

int Vazia(TLista Lista){
    return(Lista.primeiro == Lista.ultimo);
}

void Inserir(Produto x, TLista *Lista){
    Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

void Imprimir(TLista Lista)
{
    TCelula *Aux;
    Aux = Lista.primeiro->prox;
    while (Aux != NULL)
    {
        printf("%d\n", Aux->item.codigo);
        Aux = Aux->prox;
    }
}

TCelula *Pesquisar(TLista Lista, Produto Item)
{
    TCelula *Aux;
    Aux = Lista.primeiro;
    while (Aux->prox != NULL)
    {
        if (Aux->prox->item.codigo == Item.codigo)
            return Aux;
        Aux = Aux->prox;
    }
    return NULL;
}

void LerProduto(Produto *x)
{
    printf("\nDigite o codigo: ");
    fflush(stdin);
    scanf("%d", &x->codigo);

    printf("\nDigite nome: ");
    fflush(stdin);
    fgets(x->nome, 50, stdin); // para strings

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

void Excluir(TLista *Lista, Produto *Item)
{
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);

    if (Aux1 != NULL)
    {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *Item = Aux2->item;

        if (Aux1->prox == NULL)
        {
            Lista->ultimo = Aux1;
        }
        free(Aux2);
        Lista->tamanho--;
    }
    else
    {
        Item->codigo = -1;
    }
}

void ImprimirProduto(Produto x)
{
    printf("\n Codigo:%d", x.codigo);
    printf("\n Nome:%s", x.nome);
    printf("\n Quantidade:%d", x.QTD);
    printf("\n Preco:%f", x.preco);
    printf("\n Descricao:%s", x.descricao);
}

void Liberar(TLista *Lista){
	TCelula *Aux1, *Aux2;
    Aux1 = Lista->primeiro;
    while(Aux1->prox != NULL){
            Aux2 = Aux1->prox;
            Aux1->prox = Aux2->prox;
            if(Aux1->prox == NULL){
                Lista->ultimo = Aux1;
            }
            free(Aux2);
            Lista->tamanho--;
    }
    free(Lista -> primeiro);
}

