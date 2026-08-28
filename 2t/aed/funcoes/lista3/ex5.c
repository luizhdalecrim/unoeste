#include <stdio.h>

void Reajustar(float *salario, float percentual);

int main(void) {
    float salario, percentual;

    printf("Salário atual -> ");
    scanf("%f", &salario);

    printf("Porcentagem de ajuste -> ");
    scanf("%f", &percentual);

    Reajustar(&salario, percentual);

    printf("Salario ajustado: %.2f\n", salario);
    return 0;
}

void Reajustar(float *salario, float percentual) {
    *salario = *salario + (*salario * percentual / 100);
}
