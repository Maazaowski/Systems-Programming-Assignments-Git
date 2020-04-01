#include <stdio.h>

int main() {

    int i;
    int c = 0;
    int total = 5;

    int *p = new int[total];

    for (i = 0; i < total; i++)
    {
        p[i] = ++c;
    }

    for (i = 0; i < total; i++)
    {
        printf("%d", p[i]);
    }

    return 0;
}