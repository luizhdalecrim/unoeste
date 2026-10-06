#include <stdio.h>

#define TF 3

int main(void) {
        int caixa[TF] = { 7, 8, 9 };

        for(int i = 0; i < TF; i++) {
                printf("%d", caixa[i]);
        }
}
