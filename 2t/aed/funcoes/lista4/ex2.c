#include <stdio.h>

float calculaProducaoTotal(int quantidadeVacas, float producaoMedia);

int main(void) {
    int vacas;
    float media, total;

    printf("Digite a quantidade de vacas: ");
    scanf("%d", &vacas);

    printf("Digite a producao media por vaca: ");
    scanf("%f", &media);

    total = calculaProducaoTotal(vacas, media);

    printf("Producao total diaria: %.2f litros\n", total);

    return 0;
}

float calculaProducaoTotal(int quantidadeVacas, float producaoMedia) {
    float producaoTotal;
    producaoTotal = quantidadeVacas * producaoMedia;
    return producaoTotal;
}
