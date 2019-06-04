#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "funcoes.h"


int main()
{

    FILE *f; // registro de contas
    con *c;
    int numConta;


    c = malloc(sizeof(con)); // alocando uma conta

    if(c == NULL){
        printf("Erro ao alocar na memória");
        exit(1);
    }

    con *listaContas = c;
    con *antConta = NULL; // Sentinela

    f = fopen("contas.txt","r+");

    if(f==NULL) {
        printf("Nao foi possivel abrir o arquivo contas.txt.\n");
        exit(1);
    }else{
        printf("\nCarregando lista de contas na memória ...\n");
        while (fscanf(f,"%d %d %d %d %d %d %s %d %s %lf %lf",&c->ccn, &c->cce, &c->cp, &c->agencia, &c->nConta, &c->senha, c->c.nome, &c->c.idade, c->c.cpf, &c->saldo, &c->limite) == 11 ){
            c->prox = malloc(sizeof(con)); // aloca um novo nó para a proxima conta
            antConta = c; // sentinela para conta antes do fim
            c = c->prox;
        }
        numConta = antConta->nConta + 1;
    }


    char novamente[1];
    int opcao, opBox, opAdm;
    do{
        inicio();
        scanf("%d",&opcao);
        if(opcao == 1){
            int nAgencia, nConta, nSenha;
            printf("\n\n### CAIXA ELETRONICO - Autenticacao ###");
            printf("\n Número Agencia\n:");
            scanf("%d",&nAgencia);
            printf("\n Número Conta\n:");
            scanf("%d",&nConta);
            printf("\n Senha\n:");
            scanf("%d",&nSenha);
            con usuarioAutenticado = checkUser(listaContas,nAgencia,nConta,nSenha);
            if(usuarioAutenticado.senha == nSenha){
                 menuCaixa();
                 scanf("%d",&opBox);
                if(opBox == 1){

                }else if(opBox == 3){
                    printf("Saldo atual: %.2lf", usuarioAutenticado.saldo);
                }
            }else{
                printf("Dados informados inválidos!\n");
            }
        }else if(opcao == 2){
           menuGerencial();
           scanf("%d",&opAdm);
           if(opAdm == 1){
                char nome[50], cpf[11], tentar[1], dest[50];
                int tipo, senha, idade;
                printf("Digite o seu nome\n:");
                scanf("%s",nome);
                printf("Digite sua idade\n:");
                scanf("%d", &idade);
                if(!checkIdade(idade)){
                    printf("Idade não permitada para criar conta no banco!");
                    break;
                }
                strcpy(dest, nome);
                do{
                    tentar[0] = 'n';
                    printf("Digite seu CPF de acordo com o formato abaixo\nxxxxxxxxxxx\n:");
                    scanf("%s",cpf);
                    if(!checkCpf(cpf)){
                        printf("Formato de CPF inválido\nTentar novamente? [s]im / [n]ao\n:");
                        scanf("%c",tentar);
                    }
                }while(tentar[0] != 'n');
                do{
                    printf("Selecione o tipo da conta\n:");
                    tipoConta();
                    scanf("%d", &tipo);
                }while(tipo < 0 || tipo > 3);
                do{
                    printf("Escolha senha\nObs: Não pode comecar com 0\nSo pode conter números de: 0 a 9\n:");
                    scanf("%d", &senha);
                }while(senha < 100000 || senha > 999999);
                if(tipo == 1){
                    fprintf(f,"1 0 0 1000 %d %d %s %d %s 0 %.2lf\n",numConta++,senha,dest,idade,cpf,(idade*100.0));
                }else if(tipo == 2){
                    fprintf(f,"0 1 0 1000 %d %d %s %d %s 0 %.2lf\n",numConta++,senha,dest,idade,cpf,(idade*100.0));
                }else{
                    fprintf(f,"0 0 1 1000 %d %d %s %d %s 0 %.2lf\n",numConta++,senha,dest,idade,cpf,(idade*100.0));
                }
                printf("Conta criada com sucesso!");

           }else if(opAdm == 2){
                // FAREI OUTRA HORA
                break;
           }else if(opAdm == 3){
                // remover_conta(listaContas, cpf);
                // FALTA IMPLEMENTAR O RESTO
                break;
           }else if(opAdm == 4){
                listar_contas(listaContas);
           }else{
                break;
           }
        }else if(!opcao){
            break;
        }else{
            printf("Opcao invalida, vamos tentar novamente? [s]im / [n]ao\n");
            scanf("%s",novamente);
        }
    }while(strcmp(novamente,"s"));

    fclose(f);
    free(c);
    return 0;
}
