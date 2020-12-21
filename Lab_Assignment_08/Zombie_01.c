#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        int pid;
        pid = fork();
        if( pid == 0 )
        {
                printf("\nChild Process\n");
        }
        else if( pid > 0 )
        {
                sleep(5);
                printf("\nParent Process\n");
                printf("Zombie Process\n");
                while(1)
                {
                };
                return 1;
        }
}
