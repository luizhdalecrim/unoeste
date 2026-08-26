#include <stdio.h>

int soma_multiplos_vetor(int N);

int main(void) {
    int N;

    printf("N -> ");
    scanf("%d", &N);

    int resultado = soma_multiplos_vetor(N);

    printf("Soma dos multiplos de 3 ou 5 abaixo de %d: %d\n", N, resultado);

    return 0;
}

int soma_multiplos_vetor(int N) {
    int vetor[N];
    int soma = 0;

    for (int i = 0; i < N; i++) {
        vetor[i] = i;
    }

    for (int i = 0; i < N; i++) {
        if (vetor[i] % 3 == 0 || vetor[i] % 5 == 0) {
            soma += vetor[i];
        }
    }

    return soma;
}
