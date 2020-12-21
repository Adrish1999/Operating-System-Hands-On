#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        int pid = fork();
        if (pid > 0)
        {
                printf("\nParent process\n");
                printf("ID : %d\n\n",getpid());
        }
        else if (pid == 0)
        {
                printf("\nChild process\n");

                printf("ID: %d\n",getpid());
                printf("Parent -ID: %d\n\n",getppid());

                sleep(5);


                printf("\nOrphan process \n");
                printf("ID: %d\n",getpid());
                printf("Parent -ID: %d\n",getppid());
        }
        else
        {
                printf("Failed to create child process");
        }

        return 0;
}
