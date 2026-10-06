#include <stdio.h>
#include <string.h>

int main(void) {
        char primeiro_nome[25];
        char sobrenome[25];

        char nome_completo[50];

        // Leitura de string com scanf().
        printf("Digite o seu primeiro nome -> ");
        scanf("%s", primeiro_nome);
        setbuf(stdin, NULL);

        printf("Olá, %s!\n", primeiro_nome);

        // Leitura de string com gets().
        printf("Digite o seu sobrenome -> ");
        fgets(nome_completo, sizeof(nome_completo), stdin);
        setbuf(stdin, NULL);

        printf("Nome completo: %s\n", nome_completo);

        // Usando biblioteca string.h.
        strcpy(primeiro_nome, nome_completo);
        strcat(sobrenome, nome_completo);



        printf("Nome completo: %s\n", nome_completo);

        return 0;
}
