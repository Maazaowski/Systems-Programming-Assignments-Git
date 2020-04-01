#include <stdio.h>

struct s1 {

    char a;
    int b;
    char c;

};

struct s2 {

    int a;
    char b[1];
    char c[2];
    char d[3];
    char e[4];
    char f[5];
    int g;

};

int main() {
    //int i;
    struct s1 ST1;
    struct s2 ST2;
    char i;

    printf("Address of Structure 1: %u\n", &ST1);
    printf("Address of Structure 2: %u\n", &ST2);

    printf("Size of Structure 1: %d\n", sizeof(ST1));
    printf("Size of Structure 2: %d\n", sizeof(ST2));
}