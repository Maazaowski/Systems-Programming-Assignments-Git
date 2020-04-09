#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char command[1024];

    int ci = read(STDIN_FILENO, command, sizeof(command));

    if (ci < 0)
    {
        perror("Reading command: ");
        exit(-1);
    }
    command[ci - 1] = '\0';

    char delim[] = " ";
    char *ptr = strtok(command, delim);

    if (strcmp(ptr, "cp") == 0)
    {
        ptr = strtok(NULL, delim);
        //int ou = write(STDOUT_FILENO, "YES\n", sizeof("YES\n"));
        if (ptr == NULL)
        {
            int ou = write(STDOUT_FILENO, "Error! Not enough arguements\n", sizeof("Error! Not enough arguements\n"));
            exit(0);
        }
        else if (strcmp(ptr, "-r") == 0)
        {

            ptr = strtok(NULL, delim);
            char source[strlen(ptr)];
            
            //int s = sizeof(*ptr);
            strcpy(source, ptr);
            
            ptr = strtok(NULL, delim);
            char dest[strlen(ptr)];
            //int d = sizeof(*ptr);
            strcpy(dest, ptr);
            //printf("%d   %d\n", strlen(source), strlen(dest));
            int c = write(STDOUT_FILENO, source, sizeof(source));
            c = write(STDOUT_FILENO, "\n", sizeof("\n"));
            c = write(STDOUT_FILENO, dest, sizeof(dest));
        }
        else
        {
            char source[strlen(ptr)];
            
            //int s = sizeof(*ptr);
            strcpy(source, ptr);
            
            ptr = strtok(NULL, delim);
            char dest[strlen(ptr)];
            //int d = sizeof(*ptr);
            strcpy(dest, ptr);
            //printf("%d   %d\n", strlen(source), strlen(dest));
            int c = write(STDOUT_FILENO, source, sizeof(source));
            c = write(STDOUT_FILENO, "\n", sizeof("\n"));
            c = write(STDOUT_FILENO, dest, sizeof(dest));

            char buffer[1024];
            int file1, file2;

            int count;

            if (strstr(source, ".") != NULL)
            {
                file1 = open(source, O_RDONLY);

                if (file1 < 0)
                {
                    perror("File 1: ");
                    exit(-1);
                }

                if (strstr(dest, ".") != NULL)
                {

                    file2 = open(dest, O_CREAT | O_RDWR);

                    if (file2 < 0)
                    {
                        perror("File 2: ");
                        exit(-1);
                    }

                    while ((count = read(file1, buffer, sizeof(buffer))) != 0)
                    {
                        write(file2, buffer, count);
                    }

                    if (close(file1) < 0)
                    {
                        perror("File 1 closing: ");
                    }

                    if (close(file2) < 0)
                    {
                        perror("File 2 closing: ");
                    }

                    return 0;
                }
                else
                {
                    int ou = write(STDOUT_FILENO, "Error! Specify filename\n", sizeof("Error! Specify filename\n"));
                    exit(0);
                }
            }
            else
            {

                int ou = write(STDOUT_FILENO, "Error! Directory not allowed. Use -r\n", sizeof("Error! Directory not allowed. Use -r\n"));
                exit(0);
            }
        }
    }
}