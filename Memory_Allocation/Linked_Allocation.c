#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	char info[50];
	int start_address;
	int size;
	struct node *link;
}N;

N *start;

void insert_at_end(char inf[], int address, int size)
{
	N *nu=(N*)malloc(sizeof(N)),*ptr;
	int i;
	for(i=0; i < sizeof(inf); i++)
	nu->info[i] = inf[i];
	nu->start_address = address;
	nu->size = size;
	nu->link=NULL;
	if(start==NULL)
	{
		start=nu;
		return;	
	}
	for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
	ptr->link=nu;
}


void display()
{
	N *ptr=start;
	printf("The linked list:\n\n");
	if(start==NULL)
	{
		printf("Empty");
		return;
	}
	while (ptr->link!=NULL)
	{
		printf("(%s, %d, %d) -->",ptr->info,ptr->start_address,ptr->size);
		ptr=ptr->link;
	}
	printf("(%s, %d, %d)",ptr->info,ptr->start_address,ptr->size);
}

int main()
{
	insert_at_end("A",0,50);
	insert_at_end("Hole",49,75);
	insert_at_end("B",124,100);
	insert_at_end("Hole",224,175);
	insert_at_end("C",399,300);
	display();
	return 0;
	
}
