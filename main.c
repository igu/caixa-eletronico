#include <stdio.h>
#include <stdlib.h>



void menuCaixa(){
    printf("\n\n### CAIXA ELETRONICO - Consulte sua conta ###");
    printf("\n                  =========================\n");
    printf("                  |     1 - Sacar           |\n");
    printf("                  |     2 - Depositar       |\n");
    printf("                  |     3 - Verifcar saldo  |\n");
    printf("                  |     0 - Sair            |\n");
    printf("                  =========================\n");
}

void menuGerencial(){
    printf("\n\n###         Bancos Coleg's  ###");
    printf("\n                  =========================\n");
    printf("                  |     1 - Criar Conta           |\n");
    printf("                  |     2 - Alterar Conta           |\n);
    printf("                  |     3 - Deletar Conta       |\n");
    printf("                  |     0 - Sair            |\n");
    printf("                  =========================\n");
}

int main()
{
    menuGerencial();
    return 0;
}
