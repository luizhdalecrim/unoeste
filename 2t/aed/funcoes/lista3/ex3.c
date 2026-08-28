#include <stdio.h>

int tf = 10;
void Fatorial(int *vet, int tam);

int main(void) {
    int vet[tf];
    for (int i = 0; i < tf; i++) {
        printf("Insira o nro %d -> ", i + 1);
        scanf("%d", &vet[i]);
    }
    Fatorial(vet, tf);
    for (int i = 0; i < tf; i++) {
        printf("%d ", vet[i]);
    }
    return 0;
}

void Fatorial(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        int resultado = 1;
        for (int j = 1; j <= vet[i]; j++) {
            resultado = resultado * j;
        }
        vet[i] = resultado;
    }
}