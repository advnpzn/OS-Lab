#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int x = 5;
    pid = fork();

    if (pid < 0)
    {
        printf("Error creating process!\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        x++;
        printf("Child Process:\n");
        printf("Process ID : %d\n", getpid());
        printf("x value = %d\n", x);
        printf("Process id of the Parent: %d\n", getppid());
    }
    else
    {
        printf("Parent Process:\n");
        printf("Process ID : %d\n", getpid());
        printf("x value = %d\n", x);
        printf("Process ID of the shell: %d\n", getppid());
    }

    return 0;
}