#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    pid_t pid;
    int i;

    pid = fork();
    
    /* pid < 0 indicates a process creation error */
    if (pid < 0)
    {
        printf("Process creation error: %d\n", pid);
        exit(-1);
    }
    /* pid > 0 indicates a parent process */
    else if (pid > 0)
    {
        wait(NULL);
        printf("Parent starts ...\nEven Numbers : ");
        for (i = 0; i < 20; i+=2)
            printf("%d ", i);
        printf("\nParent Ends...\n");
    }
    /* pid == 0 indicates a child process */
    else if (pid == 0)
    {
        printf("Child starts..\nOdd Numbers : ");
        for (i = 1; i < 20; i+=2)
            printf("%d ", i);
        printf("\nChild Ends...\n");
    }

    return 0;
}