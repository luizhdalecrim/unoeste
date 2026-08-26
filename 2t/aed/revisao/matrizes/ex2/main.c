#include <stdio.h>

int main() {
        int matriz[1][1];
        int imenor, jmenor;

        for (int i = 0; i <= 1; i++) {
                for (int j = 0; j <= 1; j++) {
                        scanf("%d", &matriz[i][j]);

                }
        }

        printf("[%d][%d]\n", imenor, jmenor);
}
