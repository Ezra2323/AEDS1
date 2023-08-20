#include <stdio.h>
#include <stdlib.h>
#include "interfaceLista.h"

void MSG_MENU()
{
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
}

void MENU(TLista* lista1)
{
    Produto produto;
    int opcao=0;
    int i;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            system("cls");
            LerProduto(&produto);
            Inserir(produto, lista1);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            printf("Insira o codigo a ser pesquisado ");
            fflush(stdin);
            scanf("%d", &produto.codigo);
            fflush(stdin);

            TCelula *Aux= Pesquisar(*lista1, produto);

            if(Aux != NULL)
            {
                ImprimirProduto(Aux->prox->item);
                printf("\n");
            }
            else
            {
                printf("\n!produto não está na lista!\n");
            }
            system("PAUSE");
            break;
        case 3:
            system("cls");
            fflush(stdin);
            scanf("%d", &produto.codigo);
            Excluir(lista1, &produto);
            system("PAUSE");
            break;
        case 4:
            system("cls");
            Imprimir(*lista1);
            system("PAUSE");
            break;
        case 5:
            system("clear");
            printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
            system("PAUSE");

        default:
            system("clear");
            printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            system("PAUSE");
        } // fim do bloco switch
    }
    while(opcao != 5);
}
