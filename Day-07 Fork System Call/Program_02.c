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
		printf("\nChild process %d\n",++i);
	}
	else
	{
		printf("\nParent process %d\n",i);
	}
	return 0;
}


