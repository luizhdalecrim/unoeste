#include <stdio.h>

void Media(int *a, int *b);

int main(void) {
    int x, y;
    printf("Isira 2 nros inteiros -> ");
    scanf("%d %d", &x, &y);

    Media(&x, &y);

    printf("%d %d\n", x, y);
    return 0;
}

void Media(int *a, int *b) {
    int media = (*a + *b) / 2;
    *a = media;
    *b = media;
}
