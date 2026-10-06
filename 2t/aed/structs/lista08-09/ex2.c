#include <stdio.h>

struct Operacoes {
        int adicao;
        int subtracao;
        int multiplicacao;
        float divisao;
};

struct Operacoes Operacoes(int n1, int n2) {
        struct Operacoes r;
        r.adicao = n1 + n2;
        r.subtracao = n1 - n2;
        r.multiplicacao = n1 * n2;
        r.divisao = (float)n1 / n2;
        return r;
}

int main() {
        int n1 = 10, n2 = 2;

        struct Operacoes resultado = Operacoes(n1, n2);

        printf("Adicao: %d\n", resultado.adicao);
        printf("Subtracao: %d\n", resultado.subtracao);
        printf("Multiplicacao: %d\n", resultado.multiplicacao);
        printf("Divisao: %.2f\n", resultado.divisao);

        return 0;
}
