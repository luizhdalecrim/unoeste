#include <stdio.h>

int main() {
        int num = 0;
        int par = 0;

        printf("Insira um nro: ");
        scanf("%d",&num);

        if ((num % 2) != 0) par = 0;
        else par = 1;

        if (!par)
                printf("Ímpar.\n");
        else
                printf("Par.\n");

        return 0;
}
