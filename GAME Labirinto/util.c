#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

void LerProduto(TProduto *x)
{

    printf("\nDigite nome: ");
    fflush(stdin);
    fgets(x->nome, 50, stdin);

}

void ImprimirProduto(TProduto x)
{
    printf("\n\n");
    printf("\nNome: %s ",x.nome);
    printf("\n\n");
}
