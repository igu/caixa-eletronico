#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO_ESCOLHIDO 1
#define LINHA_DO_ARQUIVO 2

int checkIdade(int idade){
    if(idade >= 18) return 1;
    return 0;
}


int checkCpf(char *cpf){
    int tamanho = strlen(cpf);
    int i;
    if(tamanho != 11) return 0;
    for(i = 0; i < 11; i++)
        if(cpf[i] < '0' || cpf[i] > '9') return 0;
    return 1;
}

int listar_contas(p_con c){
    printf("\nLista de contas:\n");
    if(c != NULL){
        while (c->prox != NULL){
            printf("-----------DADOS-------------\n");
            if(c->cp == 1){
                printf("Tipo de conta: Poupanca\n");
                printf("Cliente: %s\n", c->c.nome);
                printf("Agencia: %d\n", c->agencia);
                printf("Num Conta: %d\n", c->nConta);
            }else if(c->ccn == 1){
                printf("Tipo de conta: Corrente Normal\n");
                printf("Cliente: %s\n", c->c.nome);
                printf("Agencia: %d\n", c->agencia);
                printf("Num Conta: %d\n", c->nConta);
            }else {
                printf("Tipo de conta: Corrente Especial\n");
                printf("Cliente: %s\n", c->c.nome);
                printf("Agencia: %d\n", c->agencia);
                printf("Num Conta: %d\n", c->nConta);
            }
            printf("-----------------------------\n\n");
            c = c->prox;
        }
    }else{
        printf("Lista vazia\n");
        return 1;
    }
    return 0;
}


con checkUser(p_con c, int nAgencia, int nConta, int nSenha){
    if(c != NULL){
        while (c->prox != NULL){
            if( ((c->agencia == nAgencia && c->nConta == nConta) && (c->senha == nSenha)) ) return *c;
            c = c->prox;
        }
    }else{
        return *c;
    }
    return *c;
}


int remover_conta(char *cpf, p_con c){
    // IREI IMPLEMENTAR
}
