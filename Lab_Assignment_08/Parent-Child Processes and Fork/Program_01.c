#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int p;
	p = fork();
	if(p == 0)
	{
		printf("\n%d\n",getpid());
		printf("%d\n",getppid());
	}
	return 0;
}


/*
Output:

1416748
1

*/
