#include <stdio.h>

void valor_futuro_vetor(float capital[], float taxa[], int periodo[], int tamanho);

int main() {
    int N;

    printf("Quantidade de investimentos a calcular -> ");
    scanf("%d", &N);

    float capitais[N];
    float taxas[N];
    int periodos[N];

    for (int i = 0; i < N; i++) {
        printf("\nInvestimento %d:\n", i + 1);

        printf("Capital inicial -> ");
        scanf("%f", &capitais[i]);

        printf("Taxa de juros anual (decimal, ex: 0.05) -> ");
        scanf("%f", &taxas[i]);

        printf("Periodo em anos -> ");
        scanf("%d", &periodos[i]);
    }

    valor_futuro_vetor(capitais, taxas, periodos, N);

    return 0;
}

void valor_futuro_vetor(float capital[], float taxa[], int periodo[], int tamanho) {
    float valor_futuro[tamanho];

    for (int i = 0; i < tamanho; i++) {
        valor_futuro[i] = capital[i] * (1 + taxa[i] * periodo[i]);
    }

    printf("\n--- Valores Futuros Calculados ---\n\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Investimento %d:\n Capital = %.2f\n Taxa = %.2f\n Tempo = %d ano(s)\n VF = %.2f\n",
               i + 1, capital[i], taxa[i], periodo[i], valor_futuro[i]);
        printf("\n--------------------------------\n");
    }
}

