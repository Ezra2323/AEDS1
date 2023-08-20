#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

void MENU(TPilha *pilha)
{
    TProduto Item;
    int linha, coluna;
    int i;

    //quatidade de linhas
    printf("\n\nDigite a quantidade de linhas do labirinto: ");
    fflush(stdin);
    scanf("%d", &linha);

    //quatidade de colunas
    printf("\n\nDigite a quantidade de colunas do labirinto: ");
    fflush(stdin);
    scanf("%d", &coluna);

    int[linha][coluna];

    //inserir os elementos da matriz pelo usuario
    for(i = 0; i<linha; i++){
        for(j = 0; j<coluna; j++){
            scanf("Coluna: %d", item[i][j]);
        }
    }

    //inserir esses elementos em uma pilha
       for (j = 0; j < coluna; j++) {
        for (i = 0; i < linha; i++) {
            Item.codigo = item[0][j];
            Empilhar(pilha, Item);

            printf("%d", Empilhar(pilha, Item));
        }
        printf("\n");
    }


    return 0;
}

