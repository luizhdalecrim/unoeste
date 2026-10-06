#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 200

struct Data {
        int mes;
        int ano;
};

struct Produto {
        int codigo;
        char tipo[30];
        char descricao[100];
        float preco;
        struct Data fabricacao;
        struct Data validade;
};

void lerProdutos(struct Produto produtos[], int qtd) {
        for (int i = 0; i < qtd; i++) {
                printf("\n--- Produto %d ---\n", i + 1);

                printf("Codigo: ");
                scanf("%d", &produtos[i].codigo);
                getchar();

                printf("Tipo: ");
                fgets(produtos[i].tipo, 30, stdin);
                produtos[i].tipo[strcspn(produtos[i].tipo, "\n")] = '\0';

                printf("Descricao: ");
                fgets(produtos[i].descricao, 100, stdin);
                produtos[i].descricao[strcspn(produtos[i].descricao, "\n")] = '\0';

                printf("Preco: ");
                scanf("%f", &produtos[i].preco);
                getchar();

                printf("Mes de fabricacao: ");
                scanf("%d", &produtos[i].fabricacao.mes);
                printf("Ano de fabricacao: ");
                scanf("%d", &produtos[i].fabricacao.ano);
                getchar();

                printf("Mes de validade: ");
                scanf("%d", &produtos[i].validade.mes);
                printf("Ano de validade: ");
                scanf("%d", &produtos[i].validade.ano);
                getchar();
        }
}

void relatorioPorTipo(struct Produto produtos[], int qtd, char tipoBusca[]) {
        int encontrou = 0;
        printf("\n--- Relatorio: produtos do tipo '%s' ---\n", tipoBusca);
        for (int i = 0; i < qtd; i++) {
                if (strcmp(produtos[i].tipo, tipoBusca) == 0) {
                        printf("Codigo: %d | Descricao: %s | Preco: %.2f\n",
                               produtos[i].codigo, produtos[i].descricao, produtos[i].preco);
                        encontrou = 1;
                }
        }
        if (!encontrou) printf("Nenhum produto encontrado desse tipo.\n");
}

void relatorioPorValidade(struct Produto produtos[], int qtd, int mesBusca, int anoBusca) {
        int encontrou = 0;
        printf("\n--- Relatorio: produtos com validade %02d/%d ---\n", mesBusca, anoBusca);
        for (int i = 0; i < qtd; i++) {
                if (produtos[i].validade.mes == mesBusca && produtos[i].validade.ano == anoBusca) {
                        printf("Codigo: %d | Tipo: %s | Descricao: %s\n",
                               produtos[i].codigo, produtos[i].tipo, produtos[i].descricao);
                        encontrou = 1;
                }
        }
        if (!encontrou) printf("Nenhum produto com essa validade.\n");
}

int main() {
        struct Produto produtos[MAX_PRODUTOS];

        lerProdutos(produtos, MAX_PRODUTOS);

        char tipoBusca[30];
        printf("\nDigite o tipo de produto para o relatorio: ");
        fgets(tipoBusca, 30, stdin);
        tipoBusca[strcspn(tipoBusca, "\n")] = '\0';
        relatorioPorTipo(produtos, MAX_PRODUTOS, tipoBusca);

        int mes, ano;
        printf("\nDigite o mes de validade para o relatorio: ");
        scanf("%d", &mes);
        printf("Digite o ano de validade: ");
        scanf("%d", &ano);
        relatorioPorValidade(produtos, MAX_PRODUTOS, mes, ano);

        return 0;
}
