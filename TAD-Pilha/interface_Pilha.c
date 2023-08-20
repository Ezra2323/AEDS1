#include <stdio.h>
#include <stdlib.h>

#include "interface_Pilha.h"


void MSG_MENU( )
{
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. Inserir");
    printf("  \n\t2. Pesquisar");
    printf("  \n\t3. Excluir");
    printf("  \n\t4. Imprimir");
    printf("  \n\t5. Inverter com fila");
    printf("  \n\t6. Inverter com pilha");
    printf("  \n\t7. Inverter com duas pilhas");
    printf("  \n\t8. SAIR");
}

void MENU(TPilha *pilha)
{
    TProduto produto;
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
            Empilhar(produto,pilha);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            printf("\nInforme o codigo do produto : ");
            scanf("%s", produto.nome);
            fflush(stdin);

            int recebe;
            recebe = PesquisarPilha(pilha, &produto);

            if(recebe!=0)
            {
                printf("\nO produto foi encontrado\n\n");
            }
            else
            {
                printf("O produto não foi encontrado.\n");
            }


            system("PAUSE");
            break;

        case 3:
            system("cls");
            Desempilhar(pilha, &produto);

            ImprimirProduto(produto);

            system("PAUSE");
            break;

        case 4:
            system("cls");

            ImprimirPilha(pilha);

            system("PAUSE");
            break;

        case 5:
            system("cls");

            a_InverterPilha(pilha);

            system("PAUSE");
            break;
        case 6:
            system("cls");

            b_InverterPilha(pilha);

            system("PAUSE");
            break;
        case 7:
            system("cls");

            c_InverterPilha(pilha);

            system("PAUSE");
            break;
        case 8:
            system("clear");
            printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
            LiberarPilha(pilha);
            system("PAUSE");
            break;
        default:
            system("clear");
            printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            system("PAUSE");
        } // fim do bloco switch
    }
    while(opcao != 5);
}
