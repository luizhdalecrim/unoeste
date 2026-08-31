#include <stdio.h>

void zeraMultiplosDeCinco(int vetor[5]);

int main() {
    int numeros[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    zeraMultiplosDeCinco(numeros);

    printf("Vetor apos o ajuste: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}

void zeraMultiplosDeCinco(int vetor[5]) {
    for (int i = 0; i < 5; i++) {
        if (vetor[i] % 5 == 0) {
            vetor[i] = 0;
        }
    }
}
