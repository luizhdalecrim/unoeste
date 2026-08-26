#include <stdio.h>

int conta_palavras(char frase[]) {
    int contador_espacos = 0;
    int i = 0;

    while (frase[i] != '\0') {
        if (frase[i] == ' ') {
            contador_espacos++;
        }
        i++;
    }

    return contador_espacos + 1;
}

int main() {
    char texto[100];

    printf("Digite uma frase -> ");
    fgets(texto, sizeof(texto), stdin);

    int resultado = conta_palavras(texto);

    printf("Quantidade de palavras: %d\n", resultado);

    return 0;
}
