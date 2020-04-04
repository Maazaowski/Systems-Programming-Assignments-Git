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
    char IPc[16];

    fgets(IPc, 16, stdin);
    struct in_addr ip; 
    ip.s_addr = inet_addr(IPc);

    printf("4-byte unsigned integer: %u \n", ip.s_addr);

    char *IP;
    IP = inet_ntoa(ip);

    printf("IP address: %s \n", IP);



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

printf("Host entry: %s\n", *host_entry->h_addr_list[0]);

IPbuffer = inet_ntoa(*((struct in_addr*)
                        host_entry->h_addr_list[0]));

printf("Hostname: %s\n", hostbuffer);
printf("Host IP: %s\n", IPbuffer);





}