#include <stdio.h>

int main() {
        float nota[5][3];

        for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                        printf("Entre com a %dª nota do aluno %d -> ", (j + 1), i);
                        scanf("%2f", &nota[i][j]);
                }
        }

        return 0;
}
