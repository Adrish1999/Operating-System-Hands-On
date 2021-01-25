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



/*
Output:

Child Process

Parent Process
Zombie Process

1416564 pts/0    00:02:16 p1.out
1416565 pts/0    00:00:00 p1.out <defunct>


*/
