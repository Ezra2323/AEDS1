#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"


void PVazia(TPilha *Pilha)
{
    Pilha->topo =(TCelula *) malloc(sizeof(TCelula));
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



void LiberarPilha(TPilha *Pilha){

    TProduto x;
    while (!FPVazia(*Pilha))
    {
        Desempilhar(Pilha, &x);
    }

    free(Pilha->topo);

}

void preencherPilha(int linhas, int colunas, char matriz[linhas][colunas], TPilha *pilha)
{
    int contadorE = 0, contadorM = 0;
    TProduto x;

    printf("--------------------------------------         ---------------------------------------\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.Labirinto-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("--------------------------------------         ---------------------------------------\n");
    for (int i = 1; i < linhas - 1; i++)
    {
        for (int j = 1; j < colunas - 1; j++)
        {
            printf("\n-----Posi��o (%d, %d): ", i, j);
            scanf(" %c", &x.nome[0]);

            if (x.nome[0] == 'm' && contadorM < 1)
            {
                contadorM++;
                Empilhar(x,pilha);
            }
            else if (x.nome[0] == 'e' && contadorE < 1)
            {
                contadorE++;
                Empilhar(x,pilha);
            }
            else if(x.nome[0] == 'm' && contadorM == 1)
            {
                matriz[i][j] = '0';
            }
            else if(x.nome[0] == 'e' && contadorE == 1)
            {
                Empilhar(x,pilha);
            }
            else
            {
                Empilhar(x,pilha);
            }
        }
    }
    if(contadorM < 1)
    {
        printf("\n\nDigite a posicao do rato !\n\n");
        preencherPilha(linhas, colunas, matriz, pilha);
    }
    if(contadorE < 1)
    {
        printf("\n\nDigite a posicao da saida !\n\n");
        preencherPilha(linhas, colunas, matriz, pilha);
    }
}

void lerArquivoCaracterePorCaractere(TPilha *pilha) {
    int contadorE = 0, contadorM = 0;
    TProduto x;
    char teste[50];
    FILE *arq;

    printf("--------------------------------------         ---------------------------------------\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.Labirinto-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("--------------------------------------         ---------------------------------------\n");

    printf("Informe o arquivo (.txt): ");
    scanf("%s", teste);
    arq = fopen(teste, "r");

    if (arq == NULL) {
        printf("N�o foi poss�vel abrir o arquivo.\n");
        return;

    }

    int linha, coluna;
    fscanf(arq, "%d %d", &linha, &coluna);

    char matriz[linha][coluna]; // Declare a matriz com as dimens�es lidas do arquivo

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            fscanf(arq, " %c", &matriz[i][j]);

            x.nome[0] = matriz[i][j];
            x.nome[1] = '\0';

            if (x.nome[0] == 'm' && contadorM < 1) {
                contadorM++;
                Empilhar(x, pilha);
            } else if (x.nome[0] == 'e' && contadorE < 1) {
                contadorE++;
                Empilhar(x, pilha);
            } else if (x.nome[0] == 'm' && contadorM == 1) {
                matriz[i][j] = '0';
            } else if (x.nome[0] == 'e' && contadorE == 1) {
                Empilhar(x, pilha);
            } else {
                Empilhar(x, pilha);
            }
        }
    }

    fclose(arq);
}

void instrucoes()
{
    printf("--------------------------------------         ---------------------------------------\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.Labirinto-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("--------------------------------------         ---------------------------------------\n");


    printf("\n--Considere o problema de um rato apanhado em uma armadilha e que tenta encontrar\no caminho para sa�da de um labirinto.O labirinto � implementado como uma matriz de caracteres\nbidimensional, na qualas passagens s�o marcadas com 0s, as paredes com 1s, as posi��es de sa�da\npela letra �e� e a posi��o inicial do rato pela letra �m�. Nesse programa o problema do labirinto\n� levemente generalizado permitindo que a sa�da esteja em qualquer posi��o do labirinto e permitindo\nque passagens estejam nas linhas-limite.");
    printf("\n\n--O jogo dever� seguir as seguintes intru��es:");
    printf("\n1)Voc� escolhera se quer digitar o texto ou colocar um arquivo em txt");
    printf("\n2)Se for escolhida a op��o de digitar, ser� necess�rio digitar digitar ");
}


