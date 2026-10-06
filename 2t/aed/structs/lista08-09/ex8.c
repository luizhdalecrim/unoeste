#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 3

struct Categoria {
        char nome[50];
        char descricao[100];
};

struct Produto {
        char nome[100];
        float preco;
        int quantidadeEstoque;
        struct Categoria categoria;
};

struct Produto cadastrarProduto() {
        struct Produto p;

        printf("Nome do produto: ");
        fgets(p.nome, 100, stdin);
        p.nome[strcspn(p.nome, "\n")] = '\0';

        printf("Preco: ");
        scanf("%f", &p.preco);
        getchar();

        printf("Quantidade em estoque: ");
        scanf("%d", &p.quantidadeEstoque);
        getchar();

        printf("Nome da categoria: ");
        fgets(p.categoria.nome, 50, stdin);
        p.categoria.nome[strcspn(p.categoria.nome, "\n")] = '\0';

        printf("Descricao da categoria: ");
        fgets(p.categoria.descricao, 100, stdin);
        p.categoria.descricao[strcspn(p.categoria.descricao, "\n")] = '\0';

        return p;
}

void exibirProduto(struct Produto p) {
        printf("\n--- Produto ---\n");
        printf("Nome: %s\n", p.nome);
        printf("Preco: %.2f\n", p.preco);
        printf("Estoque: %d unidades\n", p.quantidadeEstoque);
        printf("Categoria: %s (%s)\n", p.categoria.nome, p.categoria.descricao);
}

void buscarPorCategoria(struct Produto produtos[], int qtd, char categoriaBusca[]) {
        int encontrou = 0;
        for (int i = 0; i < qtd; i++) {
                if (strcmp(produtos[i].categoria.nome, categoriaBusca) == 0) {
                        exibirProduto(produtos[i]);
                        encontrou = 1;
                }
        }
        if (!encontrou) {
                printf("Nenhum produto encontrado na categoria '%s'.\n", categoriaBusca);
        }
}

int main() {
        struct Produto produtos[MAX_PRODUTOS];

        for (int i = 0; i < MAX_PRODUTOS; i++) {
                printf("\n=== Cadastro do produto %d ===\n", i + 1);
                produtos[i] = cadastrarProduto();
        }

        char categoriaBusca[50];
        printf("\nDigite a categoria para buscar: ");
        fgets(categoriaBusca, 50, stdin);
        categoriaBusca[strcspn(categoriaBusca, "\n")] = '\0';

        buscarPorCategoria(produtos, MAX_PRODUTOS, categoriaBusca);

        return 0;
}
