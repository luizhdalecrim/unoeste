#include <stdio.h>

void ajustaParidade(int *primeiro, int *segundo);

int main() {
    int a, b;

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);

    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    ajustaParidade(&a, &b);

    printf("Primeiro (par): %d\n", a);
    printf("Segundo (impar): %d\n", b);

    return 0;
}

void ajustaParidade(int *primeiro, int *segundo) {
    if (*primeiro % 2 != 0) {
        *primeiro = *primeiro + 1;
    }
    if (*segundo % 2 == 0) {
        *segundo = *segundo + 1;
    }
}
