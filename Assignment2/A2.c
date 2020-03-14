#include <stdio.h>
#include <string.h>

int main() {

    int x = 10;
    int y = 20;

    printf("x = %d;   y = %d\n", x, y);
    swapV(x, y);
    printf("x = %d;   y = %d\n", x, y);
    swapR(&x, &y);
    printf("x = %d;   y = %d\n", x, y);
    swap3(&x, &y);
    printf("x = %d;   y = %d\n", x, y);

}

void swapV (int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swapR (int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap3 (int *x, int *y)
{
    int temp = x;
    x = y;
    y = temp;
}