#include <stdio.h>
#include <stdlib.h>

#include "interface_Pilha.h"

int main(){
    TPilha pilha;
    PVazia(&pilha);
    MENU(&pilha);
    return 0;
}
