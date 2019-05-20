#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main()
{
    char novamente[1];
    int opcao;
    do{
        inicio();
        scanf("%d",&opcao);
        if(opcao == 1){
            // BLOCO  DE CÓDIGO
        }else if(opcao == 2){
           // BLOCO  DE CÓDIGO
        }else if(!opcao){
            break;
        }else{
            printf("Opcao invalida, vamos tentar novamente? [s]im / [n]ao\n");
            scanf("%s",novamente);
        }
    }while(strcmp(novamente,"s"));
    return 0;
}
