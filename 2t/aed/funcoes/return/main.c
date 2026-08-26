#include <stdio.h>

float CalculaMedia(float nota1, float nota2);

int main(void) {
        float nota1 = 7.00;
        float nota2 = 10.00;

        printf("Resultado: %.2f\n", CalculaMedia(nota1, nota2));
        return 0;
}

float CalculaMedia(float nota1, float nota2) {
        float media = 0.00;

        return media = (nota1 + nota2) / 2;
}


