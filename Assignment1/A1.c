#include <stdio.h>
#include <string.h>


int main()
{
    char input1[1000];
    fgets(input1, 1000, stdin);
    //printf("%s\n", input1);
    int len = strlen(input1);
    //printf("%d", strlen(input1));
    input1[len-1] = '\0';
    char delim[] = " ";

    char *ptr = strtok(input1, delim);

        if (strcmp(ptr, "ls") == 0){
            printf("ls command is a basic command in Linux used to List files and directories. ls command comes with so many arguments and features like you can sort files and directories by Date, by Size, able to check hidden files and directories, permissions, inode information and so on.\n\n");

            if (ptr != NULL)
                ptr = strtok(NULL, delim);
            else
                exit(1);
                
            //printf("lel");
            if (strcmp(ptr, "-l") == 0)
            {
                printf("You can use ls command with argument -l to get more advance information related files and directories like Permissions, Owner, Group, Size, Created and Modified month, date and time, file name…etc…\n");
            }
            else if (strcmp(ptr, "-a") == 0)
            {
                printf("You can check hidden files and directories by using Linux ls command with argument -a.\n");
            }
            else if (strcmp(ptr, "-i") == 0 || strcmp(ptr, "-li") == 0)
            {
                printf("To check inode number of files and directories use ls command with option -i.\n");
            }
            else if (strcmp(ptr, "-o") == 0)
            {
                printf("ls command with argument -o will show owner of the files and directories and will not show the groups.\n");
            }
            else if (strcmp(ptr, "-m") == 0){
                printf("Linux ls command with option -m will list the files and directories separated by comma.\n");
            }
            else if (strcmp(ptr, "-lQ") == 0){
                printf("ls command with option -Q will list files and directories in which names of files and directories are enclosed in quotes.\n");
            }
            else if (strcmp(ptr, "-R") == 0){
                printf("you can list directories recursively using Linux ls command with the argument -R. Recursively means it will list all the directory with is all subdirectory in a tree format.\n");
            }
            else if (strcmp(ptr, "~") == 0){
                printf("ls command with ~ will switch you to home directory.\n");
            }
            else if (strcmp(ptr, "-lt") == 0){
                printf("Linux ls command with -t will list the files and directories by it’s modification date in ascending order, means the higher will be come first.\n");
            }
            else if (strcmp(ptr, "-lS") == 0){
                printf("You can sort the files and directories by it size using ls command with argument -S.\n");
            }
            else if (strcmp(ptr, "-lh") == 0){
                printf("ls command with option -h will list the size of the files and directories in Human Readable format for Example 20K (20 KB), 15M (15 MB).\n");
            }
            else if (strcmp(ptr, "-ln") == 0){
                printf("ls command with option -n will show the UID (User ID) and GID (Group ID) numbers of file and directory.\n");
            }
            else if (strcmp(ptr, "-lG") == 0){
                printf("If you want to list only Owner of the files and directories to which they are belongs and not groups then use Linux ls command with argument -G.\n");
            }
            else if (strcmp(ptr, "-g") == 0){
                printf("ls command with -g will list the group of the files and directories to which they are belongs.\n");
            }
            else if (strcmp(ptr, "-lF") == 0){
                printf("ls command with -F will list the directories with a /at end. Refer the sample output below.\n");
            }

            //exit(1);

        }
        else if (strcmp(ptr, "cp") == 0){

            printf("The cp command is a command-line utility for copying files and directories. It supports moving one or more files or folders with options for taking backups and preserving attributes.\n\n");
            ptr = strtok(NULL, delim);


            if (strcmp(ptr, "-R") == 0){
                printf("To copy a directory pass the -R flag. This will recursively copy a folder and create a copy.\n\n");

                ptr = strtok(NULL, delim);

                if (strcmp(ptr, "-v") == 0)
                {
                    printf("To show files that are being copied pass the -v option to the cp. This prints the files and folders that are being copied to standard output.\n");
                    ptr = strtok(NULL, delim);
                }
            }
            else if (strcmp(ptr, "-b") == 0)
            {
                printf("If a copy operation will overwrite a file the -b flag may be used to create a back up of the file. This copies the file into place and writes a backup file.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-S") == 0){
                printf("To specify the name of the backup file use the -S option.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-i") == 0) {
                printf("To prompt for confirmation when copying a file pass the -i flag. Normally when using the cp command a destination file will be overwritten if it exists when copying. Using the -i flag the command will prompt to overwrite the file.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-l") == 0)
            {
                printf("To create a hard link instead of copying with the cp command pass the -l option. Instead of copying the file a new file will be created that is a hard link to the data on disk. \n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "--preserve") == 0) {
                printf("To preserve file attributes (permissions, group and user owernship) pass the --preserve option along with the attributes to be preserved. By default mode, ownership and timestamps will be preserved.\n");
                ptr = strtok(NULL, delim);
            }


            ptr = strtok(NULL, delim);

            printf("Copying %s...\n", ptr);

            ptr = strtok(NULL, delim);
            printf("Copied to %s...\n", ptr);


        }
        else if (strcmp(ptr, "rm") == 0){

            printf("rm removes each file specified on the command line. By default, it does not remove directories.\n\n");
            ptr = strtok(NULL, delim);

            if ((strcmp(ptr, "-f") == 0) || (strcmp(ptr, "--force") == 0)){
                printf("Ignore nonexistant files, and never prompt before removing.\n");

            }
            else if (strcmp(ptr, "-i") == 0){
                printf("Prompt before every removal.\n");
            }
            else if (strcmp(ptr, "--interactive") == 0){
                printf("Prompt according to WHEN: never, once (-I), or always (-i). If WHEN is not specified, then prompt always.\n");
            }
            else if (strcmp(ptr, "--one-file-system") == 0){
                printf("When removing a hierarchy recursively, skip any directory that is on a file system different from that of the corresponding command line argument\n");
            }
            else if (strcmp(ptr, "--no-preserve-root") == 0){
                printf("Do not treat ""/"" (the root directory) in any special way.\n");
            }
            else if (strcmp(ptr, "--preserve-root") == 0){
                printf("Do not remove ""/"" (the root directory), which is the default behavior.\n");
            }
            else if ((strcmp(ptr, "-r") == 0) || (strcmp(ptr, "-R") == 0) || (strcmp(ptr, "--recursive") == 0)){
                printf("Remove directories and their contents recursively.\n");
            }
            else if ((strcmp(ptr, "-d") == 0) || (strcmp(ptr, "--dir") == 0)){
                printf("Remove empty directories. This option permits you to remove a directory without specifying -r/-R/--recursive, provided that the directory is empty. In other words, rm -d is equivalent to using rmdir.\n");
            }
            else if ((strcmp(ptr, "-v") == 0) || (strcmp(ptr, "--verbose") == 0)){
                printf("Verbose mode; explain at all times what is being done.\n");
            }
            else if (strcmp(ptr, "-l") == 0){
                printf("Prompt once before removing more than three files, or when removing recursively. This option is less intrusive than -i, but still gives protection against most mistakes.\n");
            }
            
            ptr = strtok(NULL, delim);

            printf("Removing file %s...\n", ptr);

        }
        else if (strcmp(ptr, "mkdir") == 0){
            printf("The mkdir command that allows you create them in the first place.\n\n");

            ptr = strtok(NULL, delim);

            if (strcmp(ptr, "-p") == 0){
                printf("Sometimes the requirement is to create a complete directory structure with a single mkdir command. This is possible, but you'll have to use the -p command line option.\n");
            }
            else if (strcmp(ptr, "-v") == 0)
            {
                printf("In case you want mkdir to display complete details of the operation it's performing, then this can be done through the -v command line option.\n");
            }

            ptr = strtok(NULL, delim);

            printf("Creating directory(ies)... %s", ptr);
        }
        else if (strcmp(ptr, "rmdir") == 0){

            printf("rmdir is a command-line utility for deleting empty directories. It is useful when you want to delete a directory only if it is empty, without needing to check whether the directory is empty or not.\n\n");

            ptr = strtok(NULL, delim);

            printf("Removing directory %s...", ptr);
        }
        else if (strcmp(ptr, "pwd") == 0){
            printf("The pwd command, like ls and cd, is one of the most frequently used Linux utilities. Regardless of the kind of user you are (newbie or pro), you'll find yourself using this command line tool a lot. So in this tutorial, we will quickly discuss the basics of pwd through some easy to understand examples.\n");
        }
        else if (strcmp(ptr, "cd") == 0){
            printf("cd command in linux known as change directory command. It is used to change current working directory.\n");

            ptr = strtok(NULL, delim);

            if (strcmp(ptr, "/") == 0)
            {
                printf("This command is used to change directory to the root directory, The root directory is the first directory in your filesystem hierarchy.\n");

            }
            else if(strcmp(ptr, "~") == 0)
            {
                printf("This command is used to change directory to the home directory.\n");
            }

        }
        else if (strcmp(ptr, "mv") == 0){

            printf("mv stands for move. mv is used to move one or more files or directories from one place to another in file system like UNIX. \n");

            ptr = strtok(NULL, delim);

            if (strcmp(ptr, "-i") == 0){
                printf("Like in cp, the -i option makes the command ask the user for confirmation before moving a file that would overwrite an existing file, you have to press y for confirm moving, any other key leaves the file as it is. This option doesn’t work if the file doesn’t exist, it simply rename it or move it to new location.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-f") == 0){
                printf("mv prompts for confirmation overwriting the destination file if a file is write protected. The -f option overrides this minor protection and overwrite the destination file forcefully and delete the source file.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-n") == 0){
                printf("With -n option, mv prevent an existing file from being overwritten. In the following example the effect is for nothing to happen as a file would be overwritten.\n");
                ptr = strtok(NULL, delim);
            }

            else if (strcmp(ptr, "-b") == 0){
                printf("With this option it is easier to take a backup of an existing file that will be overwritten as a result of the mv command. This will create a backup file with the tilde character(~) appended to it.\n");
                ptr = strtok(NULL, delim);
            }
            

            printf("Renaming file %s...\n", ptr);

            ptr = strtok(NULL, delim);
            
            printf("Renamed to %s...\n", ptr);
        
        
        }
        else {
            printf("Invalid command!\n");
            exit(-1);
        }

}