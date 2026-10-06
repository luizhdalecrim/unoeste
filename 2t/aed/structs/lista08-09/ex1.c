#include <stdio.h>
#include <string.h>

struct Personagem {
        char nome[50];
        char classe[30];
        int nivel;
        int pontosVida;
};

struct Personagem Personagem(char nome[], char classe[], int nivel, int pontosVida) {
        struct Personagem p;
        strcpy(p.nome, nome);
        strcpy(p.classe, classe);
        p.nivel = nivel;
        p.pontosVida = pontosVida;
        return p;
}

void exibirPersonagem(struct Personagem p) {
        printf("Nome: %s\n", p.nome);
        printf("Classe: %s\n", p.classe);
        printf("Nivel: %d\n", p.nivel);
        printf("Pontos de Vida: %d\n\n", p.pontosVida);
}

int main() {
        struct Personagem heroi1 = Personagem("Aragorn", "Guerreiro", 15, 120);
        struct Personagem heroi2 = Personagem("Gandalf", "Mago", 20, 90);

        exibirPersonagem(heroi1);
        exibirPersonagem(heroi2);

        return 0;
}
