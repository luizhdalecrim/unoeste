#include <stdio.h>

int produto_escalar(int vetorA[], int vetorB[], int tamanho);

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int tamanho = 3;

    int resultado = produto_escalar(a, b, tamanho);

    printf("Produto escalar: %d\n", resultado);

    return 0;
}

int produto_escalar(int vetorA[], int vetorB[], int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += vetorA[i] * vetorB[i];
    }

    return soma;
}
