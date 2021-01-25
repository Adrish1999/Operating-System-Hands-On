#include<stdio.h>
#include<unistd.h>

int main()
{
	fork();
	fork();
	fork();
	printf("Hello\n");
	return 0;
}


/*
Output:

Hello
Hello
Hello
Hello
Hello
Hello
Hello
Hello

*/
