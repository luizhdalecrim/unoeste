#include <stdio.h>
#include <string.h>

#define MAX_TITULOS 10

struct Titulo {
        char plataforma[30];
        char nome[100];
        char genero[30];
        char atorPrincipal[100];
        int duracaoMinutos;
};

void cadastrarTitulo(struct Titulo titulos[], int *total) {
        if (*total >= MAX_TITULOS) {
                printf("Voce ja cadastrou os 10 titulos do seu Top 10!\n");
                return;
        }

        struct Titulo t;

        printf("Plataforma: ");
        fgets(t.plataforma, 30, stdin);
        t.plataforma[strcspn(t.plataforma, "\n")] = '\0';

        printf("Nome do filme/serie: ");
        fgets(t.nome, 100, stdin);
        t.nome[strcspn(t.nome, "\n")] = '\0';

        printf("Genero: ");
        fgets(t.genero, 30, stdin);
        t.genero[strcspn(t.genero, "\n")] = '\0';

        printf("Ator/atriz principal: ");
        fgets(t.atorPrincipal, 100, stdin);
        t.atorPrincipal[strcspn(t.atorPrincipal, "\n")] = '\0';

        printf("Duracao (minutos): ");
        scanf("%d", &t.duracaoMinutos);
        getchar();

        titulos[*total] = t;   // copia a struct inteira para dentro do array
        (*total)++;
        printf("Cadastrado com sucesso! (%d/%d)\n", *total, MAX_TITULOS);
}

void listarTodos(struct Titulo titulos[], int total) {
        if (total == 0) {
                printf("Nenhum titulo cadastrado ainda.\n");
                return;
        }
        printf("\n--- Seu Top %d ---\n", total);
        for (int i = 0; i < total; i++) {
                printf("%d) %s | %s | Genero: %s | Ator: %s | %d min\n",
                       i + 1, titulos[i].nome, titulos[i].plataforma,
                       titulos[i].genero, titulos[i].atorPrincipal, titulos[i].duracaoMinutos);
        }
}

void listarPorGenero(struct Titulo titulos[], int total, char generoBusca[]) {
        int encontrou = 0;
        printf("\n--- Titulos do genero '%s' ---\n", generoBusca);
        for (int i = 0; i < total; i++) {
                if (strcmp(titulos[i].genero, generoBusca) == 0) {
                        printf("%s (%s)\n", titulos[i].nome, titulos[i].plataforma);
                        encontrou = 1;
                }
        }
        if (!encontrou) printf("Nenhum titulo encontrado nesse genero.\n");
}

void listarPorDuracao(struct Titulo titulos[], int total) {
         int encontrou = 0;
         printf("\n--- Titulos com duracao entre 90 e 120 minutos ---\n");
         for (int
