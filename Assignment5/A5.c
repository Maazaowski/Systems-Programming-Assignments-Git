#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void main() {

    //printf("MATLAB");
    struct dirent **namelist;
    int n;
    //printf("THE");

    n = scandir(".", &namelist, NULL, alphasort);
    if (n < 0)
    {
        perror("SCANDIR");
        exit(-1);
    }
    else {
        //printf("WHAT");
        while (n--)
        {
            printf("%s\n", namelist[n]->d_name);
            free(namelist[n]);

        }
        free(namelist);
    }


}