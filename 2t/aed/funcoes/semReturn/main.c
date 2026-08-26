#include <stdio.h>

void Media(float n1, float n2);

int main(void) {
        float n1 = 6.70;
        float n2 = 9.999999;

        Media(n1, n2);

        return 0;
}

void Media(float n1, float n2) {
        float m;
        m = (n1 + n2) / 2;

        printf("A média é igual a %.2f.\n", m);
}


