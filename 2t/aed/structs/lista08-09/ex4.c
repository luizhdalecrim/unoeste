#include <stdio.h>
#include <string.h>

struct Carro {
        char marca[50];
        char modelo[50];
        float potencia;
        int anoFabricacao;
        int numeroPortas;
};

void cadastrarCarros(struct Carro carros[], int qtd) {
        for (int i = 0; i < qtd; i++) {
                printf("\n--- Carro %d ---\n", i + 1);

                printf("Marca: ");
                fgets(carros[i].marca, 50, stdin);
                carros[i].marca[strcspn(carros[i].marca, "\n")] = '\0';

                printf("Modelo: ");
                fgets(carros[i].modelo, 50, stdin);
                carros[i].modelo[strcspn(carros[i].modelo, "\n")] = '\0';

                printf("Potencia (cv): ");
                scanf("%f", &carros[i].potencia);
                getchar();

                printf("Ano de fabricacao: ");
                scanf("%d", &carros[i].anoFabricacao);
                getchar();

                printf("Numero de portas: ");
                scanf("%d", &carros[i].numeroPortas);
                getchar();
        }
}

void exibirPorMarca(struct Carro carros[], int qtd, char marcaBusca[]) {
        int encontrou = 0;

        printf("\n--- Carros da marca %s ---\n", marcaBusca);
        for (int i = 0; i < qtd; i++) {
                if (strcmp(carros[i].marca, marcaBusca) == 0) {
                        printf("Modelo: %s | Potencia: %.1f cv | Ano: %d | Portas: %d\n",
                               carros[i].modelo, carros[i].potencia,
                               carros[i].anoFabricacao, carros[i].numeroPortas);
                        encontrou = 1;
                }
        }

        if (!encontrou) {
                printf("Nenhum carro encontrado para essa marca.\n");
        }
}

int main() {
        struct Carro carros[5];
        char marcaBusca[50];

        cadastrarCarros(carros, 5);

        printf("\nDigite a marca que deseja buscar: ");
        fgets(marcaBusca, 50, stdin);
        marcaBusca[strcspn(marcaBusca, "\n")] = '\0';

        exibirPorMarca(carros, 5, marcaBusca);

        return 0;
}
