#include <stdio.h>

int main() {
        int num;
        int matriz[3][3];
        int cont = 0;


        printf("Insira o número a procurar -> ");
        scanf("%d", &num);

        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        printf("Insira o %dº número da %dª linha -> ", j, i);
                        scanf("%d", &matriz[i][j]);

                        if (num == matriz[i][j]) cont++;
                }
        }

        printf("Quantidade: %d\n", cont);

        return 0;
}
