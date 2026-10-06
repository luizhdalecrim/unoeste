#include <stdio.h>
#include <string.h>

struct Curso {
        int codigo;
        char titulo[100];
        char instrutor[100];
        int cargaHoraria;
        float preco;
};

void lerCursos(struct Curso cursos[], int qtd) {
        for (int i = 0; i < qtd; i++) {
                printf("\n--- Curso %d ---\n", i + 1);

                printf("Codigo: ");
                scanf("%d", &cursos[i].codigo);
                getchar();

                printf("Titulo: ");
                fgets(cursos[i].titulo, 100, stdin);
                cursos[i].titulo[strcspn(cursos[i].titulo, "\n")] = '\0';

                printf("Instrutor: ");
                fgets(cursos[i].instrutor, 100, stdin);
                cursos[i].instrutor[strcspn(cursos[i].instrutor, "\n")] = '\0';

                printf("Carga horaria (horas): ");
                scanf("%d", &cursos[i].cargaHoraria);
                getchar();

                printf("Preco: ");
                scanf("%f", &cursos[i].preco);
                getchar();
        }
}

void buscarCurso(struct Curso cursos[], int qtd, int codigoBusca) {
        for (int i = 0; i < qtd; i++) {
                if (cursos[i].codigo == codigoBusca) {
                        printf("\n--- Curso Encontrado ---\n");
                        printf("Codigo: %d\n", cursos[i].codigo);
                        printf("Titulo: %s\n", cursos[i].titulo);
                        printf("Instrutor: %s\n", cursos[i].instrutor);
                        printf("Carga horaria: %d horas\n", cursos[i].cargaHoraria);
                        printf("Preco: %.2f\n", cursos[i].preco);
                        return; // achou, pode encerrar a busca
                }
        }
        printf("Curso com codigo %d nao encontrado.\n", codigoBusca);
}

void exibirMedias(struct Curso cursos[], int qtd) {
        float somaPrecos = 0;
        int somaHoras = 0;

        for (int i = 0; i < qtd; i++) {
                somaPrecos += cursos[i].preco;
                somaHoras += cursos[i].cargaHoraria;
        }

        float mediaPrecos = somaPrecos / qtd;
        float mediaHoras = (float)somaHoras / qtd;

        printf("\n--- Estatisticas Gerais ---\n");
        printf("Preco medio: %.2f\n", mediaPrecos);
        printf("Duracao media: %.2f horas\n", mediaHoras);
}

int main() {
        struct Curso cursos[10];
        int codigoBusca;

        lerCursos(cursos, 10);

        printf("\nDigite o codigo do curso que deseja buscar: ");
        scanf("%d", &codigoBusca);

        buscarCurso(cursos, 10, codigoBusca);
        exibirMedias(cursos, 10);

        return 0;
}
