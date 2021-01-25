#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int p, id = 5;
	p = fork();
	if(p < 0)
	{
		printf("\nError, child process creation failed\n");
	}
	else if(p == 0)
	{
		printf("\nChild process, %d\n",id++);
	}
	else
	{
		printf("\nParent process, %d\n",id);
	}
	return 0;
}



/*
Output:

Parent process, 5
Child process, 5

*/
