#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "principal.h"



void JOGO(TPilha *pilha)
{
    //declarar variaveis
    TProduto Item;
    int linha, coluna;
    int i,j;
    int opcao;
    TPilha tempPilha;
    TPilha mazeRows;
    PVazia(&tempPilha);
    PVazia(&mazeRows);
    int novaLinha =0;
    int novaColuna=0 ;
    int delay;

    //quatidade de linhas
    system ("cls");
    printf("--------------------------------------         ---------------------------------------\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.Labirinto-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("--------------------------------------         ---------------------------------------\n");




        printf("\n\nDigite o numero de linhas: ");
        scanf("%d", &linha);

        printf("\nDIgite o numero de colunas: ");
        scanf("%d", &coluna);
        system("cls");

    novaLinha = linha + 2;
    novaColuna  = coluna + 2;

    char matriz[novaLinha][novaColuna];



    //Opta como irá inserir o labirinto
    system("cls");
    printf("--------------------------------------         ---------------------------------------\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.Labirinto-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("--------------------------------------         ---------------------------------------\n");
    printf("\n1)Inserir arquivo (.txt)\n2)Inserir pelo teclado");
    printf("\n\nDigite uma opcao: ");
    scanf("%d", &opcao);
system("cls");
    if(opcao == 1)
    {
        lerArquivoCaracterePorCaractere(&tempPilha);

    }
    else
    {

        preencherPilha(novaLinha, novaColuna, matriz, &tempPilha);
    }



    while (!FPVazia(tempPilha))
    {
        Desempilhar(&tempPilha, &Item);
        Empilhar(Item, &mazeRows);
    }

    LiberarPilha(&tempPilha);

    //linhas são transferidas da pilha para a matriz
    printf("\n");
    Desempilhar(&mazeRows, &Item);
    for (int i = 0; i < novaLinha; i++)
    {
        for (int j = 0; j < novaColuna; j++)
        {
            matriz[i][j] = Item.nome[0];
            if(i==0 || i == (novaLinha-1) || j == 0|| j== (novaColuna - 1))
            {
                matriz[i][j] = '1';
            }
            else
            {
                matriz[i][j] = Item.nome[0];
                Desempilhar(&mazeRows, &Item);
            }
            printf("%c ", matriz[i][j]); // Usar %c para caracteres
        }
        printf("\n");
    }

    printf("\n\n");

//matriz mazeStack
    int mx, my, ex, ey;
    char mazeStack[novaLinha][novaColuna];

    for(i = 0; i<novaLinha; i++)
    {
        for(j = 0; j<novaColuna; j++)
        {
            mazeStack[i][j]= matriz[i][j];
            if(matriz[i][j] == 'm')
            {
                mx = i;
                my = j;
            }
            else if(matriz[i][j] == 'e')
            {
                ex = i;
                ey = j;
            }
        }
    }
    TProduto x, y;

   while (1)
{
      if (!FPVazia(*pilha))
        {
            printf("GANHOU!\n\n");
            break; // Sai do loop se a saída for encontrada
        }
      if(mazeStack[mx + 1][my] == 'e' || mazeStack[mx - 1][my] == 'e' || mazeStack[mx][my + 1] == 'e' || mazeStack[mx][my - 1] == 'e'){
        printf("GANHOU !!!\n\n");
        break;
    }

    // Verifica movimento para a direita
    if (mazeStack[mx][my + 1] == '0')
    {
        x.linha = mx;
        x.coluna = my + 1;
        Empilhar(x, pilha);
    }
    // Verifica movimento para baixo
    else if (mazeStack[mx + 1][my] == '0')
    {
        x.linha = mx + 1;
        x.coluna = my;
        Empilhar(x, pilha);
    }
    // Verifica movimento para a esquerda
    else if (mazeStack[mx][my - 1] == '0')
    {
        x.linha = mx;
        x.coluna = my - 1;
        Empilhar(x, pilha);
    }
    // Verifica movimento para cima
    else if (mazeStack[mx - 1][my] == '0')
    {
        x.linha = mx - 1;
        x.coluna = my;
        Empilhar(x, pilha);
    }

        Desempilhar(pilha, &y);
        mx = x.linha;
        my = x.coluna;

        mazeStack[mx][my] = '.';
  for (int i = 0; i < novaLinha; i++) {
        for (int j = 0; j < novaColuna; j++) {
            printf("%c ", mazeStack[i][j]);
            fflush(stdout); // Forçar a saída para ser exibida imediatamente
            usleep(delay); // Pausa em microssegundos
        }
        printf("\n");
        usleep(delay); // Pausa entre as linhas
    }

printf("\n");

    }
}


void MENU(TPilha *pilha)
{
    int op;
    //quatidade de linhas


    printf("--------------------------------------         ---------------------------------------\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.Labirinto-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("--------------------------------------         ---------------------------------------\n");


    printf("\n                       ************Menu de opções************\n\n");


    printf("\n  1)Jogo\n  2)Instruções do jogo e Sobre\n  3)Sair\n");
    printf("\n  Digite uma opcao: ");

    scanf("%d", &op);
    system("cls");

    if (op == 1)
    {
        JOGO(pilha);

        printf("\n1)Voltar ao jogo\n2)sair");
        fflush(stdin);
        scanf("%d", &op);
        if (op == 1)
        {
            system("cls");
            printf("\n");
            MENU(pilha);
        }
        else
        {
            return;
        }


    }
    else if (op == 2)
    {
        //lerArquivoCaracterePorCaractere("teste.txt");
        instrucoes();
        system("PAUSE");
        MENU(pilha);
    }
    else if (op == 3)
    {
        return;
    }
    else
    {
        system("cls");
        printf("Digite uma opção válida\n ");
        system("cls");
        MENU(pilha);
    }

}

