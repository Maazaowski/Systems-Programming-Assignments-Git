#include <stdio.h>
#include <string.h>

void main() {
 
 // FIRST PART
    char IP[16];
    char IPc[16];

    fgets(IPc, 16, stdin);
    strcpy(IP, IPc);

    char delim[] = ".";

    unsigned char octet[4];
    unsigned char *ptr = strtok(IP, delim);

    int i = 0;

    while (ptr != NULL)
    {
        octet[i] = (unsigned char) atoi(ptr);
        ptr = strtok(NULL, delim);
        printf("%u\n", octet[i]);
        i++;
    }

    
    char IP2[16];
    sprintf(IP2, "%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);

    printf("%s\n", IP2);

// SECOND PART


}