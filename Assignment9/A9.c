#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *f1, *f2;

    char command[1000], c;
    char file1[1000];
    char file2[1000];

    scanf("%s", command);
    char delim[] = " ";
    char *ptr = strtok(command, delim);
    printf("%s", ptr);

    ptr = strtok(NULL, delim);
    f1 = fopen(ptr, "r");

    if (f1 == NULL)
    {
        printf("Cannot open file %s \n", ptr);
        exit(-1);
    }    

    ptr = strtok(NULL, delim);
    f2 = fopen(ptr, "w");

    if (f2 == NULL)
    {
        printf("Cannot open file %s \n", ptr);
        exit(-1);   
    }

    c = fgetc(f1);
    while (c != EOF)
    {
        fputc(c, f2);
        c = fgetc(f1);
    }

    printf("Completed!");
    fclose(f1);
    fclose(f2);






}