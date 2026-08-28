#include <stdio.h>

void Ordenar(int *a, int *b);

int main(void) {
        int a, b;

        printf("Insira o nro 1 -> ");
        scanf("%d", &a);

        printf("Insira o nro 2 -> ");
        scanf("%d", &b);

        Ordenar(&a, &b);

        printf("Maior: %d\nMenor: %d\n", a, b);

        return 0;
}

void Ordenar(int *a, int *b) {
        int menor;
        if (*a < *b) {
                menor = *a;
                *a = *b;
                *b = menor;
        }
}
