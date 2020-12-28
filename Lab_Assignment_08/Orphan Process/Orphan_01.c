#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        int p;
        p = fork();
        if(p == 0)
        {
                printf("\nChild process\n");
                sleep(5);
                printf("Orphan process\n");
        }
        else if(p > 0)
        printf("\nParent proces\n");
        return 1;
}



/*
Output:

Parent proces
Child process
Orphan process

*/
