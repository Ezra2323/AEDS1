#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <locale.h>

int main()
{
    setlocale(0,"Portuguese");
    TPilha pilha;
    PVazia(&pilha);
    MENU(&pilha);
    return 0;
}
