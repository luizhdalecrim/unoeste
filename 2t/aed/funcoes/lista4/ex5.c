#include <stdio.h>

void atualizaEstoque(int *estoque, int saida);

int main() {
    int estoqueAtual, quantidadeVendida;

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &estoqueAtual);

    printf("Digite a quantidade vendida (saida): ");
    scanf("%d", &quantidadeVendida);

    atualizaEstoque(&estoqueAtual, quantidadeVendida);

    printf("Estoque atualizado: %d\n", estoqueAtual);

    return 0;
}

void atualizaEstoque(int *estoque, int saida) {
    if (saida > *estoque) {
        *estoque = 0;
    } else {
        *estoque = *estoque - saida;
    }
}
