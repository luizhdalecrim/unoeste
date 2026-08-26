#include <stdio.h>

float media_vetor(int vetor[], int tamanho);

int main() {
    int vetor[] = {3, 8, 5, 12, 7, 4};
    int tamanho = 6;

    float resultado = media_vetor(vetor, tamanho);
    printf("Media dos pares: %.2f\n", resultado);

    return 0;
}

float media_vetor(int vetor[], int tamanho) {
    int soma = 0;
    int contador = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            soma += vetor[i];
            contador++;
        }
    }

    if (contador == 0) {
        printf("Nao ha numeros pares no vetor.\n");
        return 0;
    }

    return (float) soma / contador;
}
