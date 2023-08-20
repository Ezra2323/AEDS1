#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

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

void ImprimirProduto(TProduto x)
{
    printf("\n\n");
    printf("\nCodigo: %d\n", x.codigo);
    printf("\nNome: %s ",x.nome);
    printf("Descricao: %s",x.descricao);
    printf("Preco: R$ %.2f\n", x.preco);
    printf("\nQuantidade: %d\n", x.QTD);
    printf("\n\n");
}
