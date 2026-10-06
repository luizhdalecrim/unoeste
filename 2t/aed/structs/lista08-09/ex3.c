#include <stdio.h>
#include <string.h>

struct Livro {
        char titulo[100];
        char autor[100];
        int anoPublicacao;
};

void lerLivros(struct Livro livros[], int qtd) {
        for (int i = 0; i < qtd; i++) {
                printf("\nLivro %d:\n", i + 1);

                printf("Titulo: ");
                fgets(livros[i].titulo, 100, stdin);
                livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0';

                printf("Autor: ");
                fgets(livros[i].autor, 100, stdin);
                livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0';

                printf("Ano de publicacao: ");
                scanf("%d", &livros[i].anoPublicacao);
                getchar(); // limpa o \n para o proximo fgets
        }
}

void listarLivros(struct Livro livros[], int qtd) {
        printf("\n--- Lista de Livros ---\n");
        for (int i = 0; i < qtd; i++) {
                printf("Titulo: %s | Autor: %s | Ano: %d\n",
                       livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
        }
}

void listarPorAno(struct Livro livros[], int qtd) {
        int ano, encontrou = 0;
        printf("Digite o ano de publicacao desejado: ");
        scanf("%d", &ano);
        getchar();

        printf("\n--- Livros de %d ---\n", ano);
        for (int i = 0; i < qtd; i++) {
                if (livros[i].anoPublicacao == ano) {
                        printf("Titulo: %s | Autor: %s\n", livros[i].titulo, livros[i].autor);
                        encontrou = 1;
                }
        }
        if (!encontrou) {
                printf("Nenhum livro encontrado para esse ano.\n");
        }
}

int main() {
        struct Livro livros[10];
        int opcao;

        do {
                printf("\n--- MENU ---\n");
                printf("1 - Ler vetor de livros\n");
                printf("2 - Listar todos os livros\n");
                printf("3 - Listar livros de um ano especifico\n");
                printf("4 - Sair\n");
                printf("Escolha: ");
                scanf("%d", &opcao);
                getchar();

                switch (opcao) {
                        case 1: lerLivros(livros, 10); break;
                        case 2: listarLivros(livros, 10); break;
                        case 3: listarPorAno(livros, 10); break;
                        case 4: printf("Saindo...\n"); break;
                        default: printf("Opcao invalida!\n");
                }
        } while (opcao != 4);

        return 0;
}
