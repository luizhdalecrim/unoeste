#include <stdio.h>

#define TF 50

typedef struct {
        char nome[TF];
        float saldo;
} Carteira;

typedef struct {
        Carteira origem;
        Carteira destino;
        int tipo; // Entrada = 1; Saída = 0. 
        float quantia;
} Operacao;

void CadastrarCarteira(Carteira carteiras[TF], int tl_carteiras);
void ExibirCarteira(Carteira carteiras[TF]);
void RealizarOperacao(Operacao operacoes[TF], Operacao operacao);

int main(void) {
        int tl_carteiras = 0;
        int tl_operacoes = 0;

        Carteira carteiras[TF];
        Operacao operacoes[TF];

        int opcao;
        do {
                printf("1 - Cadastrar Carteira\n");
                printf("2 - Exibir Carteira\n");
                printf("3 - Realizar Pagamento\n");
                printf("4 - Adicionar Crédito\n");
                printf("0 - Sair\n");
                printf("-> ");
                scanf("%d", &opcao);
                setbuf(stdin, NULL);

                switch (opcao) {
                        case 1:
                                CadastrarCarteira(&carteiras[tl_carteiras], tl_carteiras);
                                tl_carteiras++;
                                break;
                        case 2:
                                // ExibirCarteira(&carteiras[TF]);
                                break;
                        case 3:
                                // Operacao *saida;
                                // saida->tipo = 0;
                                // RealizarOperacao(&operacoes[TF], saida);
                                // tl_operacoes++;
                                break;
                        case 4:
                                // Operacao *entrada;
                                // entrada->tipo = 1;
                                // RealizarOperacao(&operacoes[TF], entrada);
                                tl_operacoes++;
                                break;
                }
        } while (opcao != 0);

        return 0;
}

void CadastrarCarteira(Carteira carteiras[TF], int tl_carteiras) {
        Carteira nova_carteira;

        printf("Nome -> ");
        fgets(&nova_carteira.nome[tl_carteiras], sizeof(&nova_carteira.nome[tl_carteiras]), stdin);
        setbuf(stdin, NULL);
        printf("Saldo -> ");
        scanf("%f", &nova_carteira.saldo);
        setbuf(stdin, NULL);

        carteiras[tl_carteiras] = nova_carteira;
}

void ExibirCarteira(Carteira carteiras[TF]) {

}

void RealizarOperacao(Operacao operacoes[TF], Operacao operacao) {

}

