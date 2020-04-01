#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

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

char hostbuffer[256];
char *IPbuffer;
struct hostent *host_entry;

int hostname;

hostname = gethostname(hostbuffer, sizeof(hostbuffer));

if (hostname == -1)
{
    perror("Hostname: ");
    exit(-1);
}
//printf("Test: %s\n");
host_entry = gethostbyname(hostbuffer);

if (host_entry == NULL)
{
    perror("Host_Entry: ");
    exit(-1);
}

IPbuffer = inet_ntoa(*((struct in_addr*)
                        host_entry->h_addr_list[0]));

printf("Hostname: %s\n", hostbuffer);
printf("Host IP: %s\n", IPbuffer);
}