#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

   char buffer[1024];
   int file1, file2;

   int count;

   file1 = open("sample.mp4", O_RDONLY);

   if (file1 < 0)
   {
       perror("File 1: ");
       exit(-1);
   }

   file2 = open("sample2.mp4", O_CREAT | O_RDWR);

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