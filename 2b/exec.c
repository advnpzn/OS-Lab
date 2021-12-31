#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    switch (pid = fork()) 
    {
        case -1:
            perror("Fork Failed :(");
            exit(-1);
        
        case 0:
            printf("Child Process:\n");
            execl("/bin/date", "date", 0);
            exit(0);

        default:
            wait(NULL);
            printf("\nChild Terminated!");
            exit(0);
    }

    return 0;
}