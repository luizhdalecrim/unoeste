#include <stdio.h>
#define TF 3

void getMaior(int *nros, int *maior);

int main(void) {
        int nros[TF];
        int maior;

        for (int i = 0; i < TF; i++) {
                printf("Insira o %d nro -> ", (i + 1));
                scanf("%d", &nros[i]);
        }

        getMaior(nros, &maior);
        printf("Maior: %d", maior);
        return 0;
}

void getMaior(int *nros, int *maior) {
        *maior = nros[0];
        for (int i = 1; i < TF; i++) {
                if (nros[i] > *maior) {
                        *maior = nros[i];
                }
        }
}
