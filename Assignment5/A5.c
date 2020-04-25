#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

struct file
{
    char filename[1000];
    int filesize;
    char access[10];

    struct file *next;
};

struct directory
{
    char dname[1000];
    char access[10];
    int filescount;
    int dircount;

    struct directory *next;
};

int main()
{
    struct file *fprev, *fhead, *fp;
    struct directory *dprev, *dhead, *dp;
    struct dirent **namelist;
    struct dirent **seminamelist;
    struct stat fileStat;
    int n;
    int fc;
    int dc;
    fhead = NULL;
    dhead = NULL;
    int m;
    char file[100];
    char path[] = "/home/maaz/Downloads/";
    n = scandir(path, &namelist, NULL, alphasort);

    while (n--)
    {
        //printf("%d\n", namelist[n]->d_type);
        if (namelist[n]->d_type == 4)
        {
            //printf("Direc\n");
            dp = malloc(sizeof(struct directory));
            sprintf(&dp->dname, "%s", namelist[n]->d_name);
            bzero(file, sizeof(file));
            strcpy(file, path);
            strcat(file, namelist[n]->d_name);
            m = scandir(file, &seminamelist, NULL, alphasort);
            fc = 0;
            dc = 0;
            //printf("SCANNED FILES: %d\n", m);
            while (m--)
            {
                if (seminamelist[m]->d_type == 4)
                    dc++;
                else
                    fc++;
            }
            dp->dircount = (int) dc;
            dp->filescount =(int) fc;
            //printf("%s\n", file);
            if (stat(file, &fileStat) < 0)
            {
                perror("Directory: ");
                exit(-1);
            }

            if (S_ISDIR(fileStat.st_mode))
            {
                dp->access[0] = 'd';
            }
            else
            {
                dp->access[0] = '-';
            }
            if (fileStat.st_mode & S_IRUSR)
            {
                dp->access[1] = 'r';
            }
            else
            {
                dp->access[1] = '-';
            }
            if (fileStat.st_mode & S_IWUSR)
            {
                dp->access[2] = 'w';
            }
            else
            {
                dp->access[2] = '-';
            }

            if (fileStat.st_mode & S_IXUSR)
            {
                dp->access[3] = 'x';
            }
            else
            {
                dp->access[3] = '-';
            }
            if (fileStat.st_mode & S_IRGRP)
            {
                dp->access[4] = 'r';
            }
            else
            {
                dp->access[4] = '-';
            }

            if (fileStat.st_mode & S_IWGRP)
            {
                dp->access[5] = 'w';
            }
            else
            {
                dp->access[5] = '-';
            }
            if (fileStat.st_mode & S_IXGRP)
            {
                dp->access[6] = 'x';
            }
            else
            {
                dp->access[6] = '-';
            }
            if (fileStat.st_mode & S_IROTH)
            {
                dp->access[7] = 'r';
            }
            else
            {
                dp->access[7] = '-';
            }
            if (fileStat.st_mode & S_IWOTH)
            {
                dp->access[8] = 'w';
            }
            else
            {
                dp->access[8] = '-';
            }
            if (fileStat.st_mode & S_IXOTH)
            {
                dp->access[9] = 'x';
            }
            else
            {
                dp->access[9] = '-';
            }

            dp->next = NULL;
            if (dhead == NULL)
            {
                dhead = dp;
            }
            else
            {
                dprev->next = dp;
            }
            dprev = dp;
        }
        else
        {
            // printf("File\n");
            fp = malloc(sizeof(struct file));
            sprintf(&fp->filename, "%s", namelist[n]->d_name);
            bzero(file, sizeof(file));
            strcpy(file, path);
            strcat(file, namelist[n]->d_name);
            if (stat(file, &fileStat) < 0)
            {
                perror("File: ");
                exit(-1);
            }
            //printf("%d bytes\n", fileStat.st_size);
            
            fp->filesize = (int) fileStat.st_size;
            //sprintf(fp->filesize, "%d", fileStat.st_size);
            if (S_ISDIR(fileStat.st_mode))
            {
                fp->access[0] = 'd';
            }
            else
            {
                fp->access[0] = '-';
            }
            if (fileStat.st_mode & S_IRUSR)
            {
                fp->access[1] = 'r';
            }
            else
            {
                fp->access[1] = '-';
            }
            if (fileStat.st_mode & S_IWUSR)
            {
                fp->access[2] = 'w';
            }
            else
            {
                fp->access[2] = '-';
            }

            if (fileStat.st_mode & S_IXUSR)
            {
                fp->access[3] = 'x';
            }
            else
            {
                fp->access[3] = '-';
            }
            if (fileStat.st_mode & S_IRGRP)
            {
                fp->access[4] = 'r';
            }
            else
            {
                fp->access[4] = '-';
            }

            if (fileStat.st_mode & S_IWGRP)
            {
                fp->access[5] = 'w';
            }
            else
            {
                fp->access[5] = '-';
            }
            if (fileStat.st_mode & S_IXGRP)
            {
                fp->access[6] = 'x';
            }
            else
            {
                fp->access[6] = '-';
            }
            if (fileStat.st_mode & S_IROTH)
            {
                fp->access[7] = 'r';
            }
            else
            {
                fp->access[7] = '-';
            }
            if (fileStat.st_mode & S_IWOTH)
            {
                fp->access[8] = 'w';
            }
            else
            {
                fp->access[8] = '-';
            }
            if (fileStat.st_mode & S_IXOTH)
            {
                fp->access[9] = 'x';
            }
            else
            {
                fp->access[9] = '-';
            }

            fp->next = NULL;
            if (fhead == NULL)
            {
                fhead = fp;
            }
            else
            {
                fprev->next = fp;
            }
            fprev = fp;
        }
    }

    fp = fhead;
    printf("--------FILES----------------\n");
    while (fp != NULL)
    {
        printf("%s\t  %s\t  %d bytes\n", fp->filename, fp->access, fp->filesize);
        fp = fp->next;
    }

    dp = dhead;
    printf("---------DIRECTORIES--------\n");
    while (dp != NULL)
    {
        printf("%s\t  %s\t  %d folders\t  %d files\n", dp->dname, dp->access, dp->dircount, dp->filescount);
        dp = dp->next;
    }
}