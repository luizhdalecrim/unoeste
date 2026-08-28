#include <stdio.h>

void Dobro(int *num);
void Metade(int *num);

int main(void) {
        int num;

        printf("Insira o nro -> ");
        scanf("%d", &num);

        Dobro(&num);

        printf("2x = %d\n", num);

        Metade(&num);

        printf("x/2 = %d\n", num);

        return 0;
}

void Dobro(int *num) {
        *num = *num * 2;
}
void Metade(int *num) {
        *num = *num / 2;
}
