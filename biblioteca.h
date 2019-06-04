#define CHAR_TAM 50

struct cliente {
    char nome[CHAR_TAM];
    int idade;
    char cpf[11];
};


typedef struct conta con, *p_con;
struct conta {
    int ccn; // tipo: conta corrente normal -> 0 (false)
    int cce; // tipo: conta corrente especial -> 0 (false)
    int cp; //  tipo: conta poupanca -> 0 (false)
    int agencia;
    int nConta;
    int senha; // senha: 6 digitos max...
    struct cliente c; // tipo: cliente
    float saldo;
    float limite;
    p_con prox;
};

void inicio(){
    printf("\n\n###         Bancos Coleg's  - Um novo conceito em Banco ###");
    printf("\n                  =========================\n");
    printf("                  |     1 - Caixa Eletronico |\n");
    printf("                  |     2 - Modulo Gerencial |\n");
    printf("                  |     0 - Sair             |\n");
    printf("                  =========================\n");
    printf("                  Digite a opcao desejada: ");
}




void menuCaixa(){
    printf("\n\n### CAIXA ELETRONICO - Consulte sua conta ###");
    printf("\n                  =========================\n");
    printf("                  |     1 - Sacar           |\n");
    printf("                  |     2 - Depositar       |\n");
    printf("                  |     3 - Verificar saldo  |\n");
    printf("                  |     0 - Sair            |\n");
    printf("                  =========================\n");
}

void menuGerencial(){
    printf("\n\n###         Bancos Coleg's  - Um novo conceito em Banco ###");
    printf("\n                  =========================\n");
    printf("                  |     1 - Criar Conta     |\n");
    printf("                  |     2 - Alterar Conta   |\n");
    printf("                  |     3 - Deletar Conta   |\n");
    printf("                  |     4 - Listar Contas   |\n");
    printf("                  |     0 - Sair            |\n");
    printf("                  =========================\n");
}


void tipoConta(){
    printf("\n                  ==================================\n");
    printf("                  |     1 - Conta Corrente Normal     |\n");
    printf("                  |     2 - Conta Corrente Especial   |\n");
    printf("                  |     3 - Conta Poupanca            |\n");
    printf("                  ====================================\n");
}

