#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char info[50];
	int start_address;
	int size;
	struct node *link;
}N;

N *start;


void insert_at_end(char *inf, int address, int size) //Method to insert node at end of linked list
{
	N *nu=(N*)malloc(sizeof(N)),*ptr;
	int i;
	
	for(i=0; i < 8; i++)
	{
		nu->info[i] = inf[i];
	}

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



void insert_at_posi(int p,int prev_start_address, int prev_size, int current_size, int info) //Method to insert node at a desired position in the linked list
{
	N *nu=(N*)malloc(sizeof(N)),*ptr=start,*prev=start;
	int c=0;
	char text[] = "PX";
	
	nu->size = current_size;
	nu->start_address = prev_start_address +  prev_size;

	text[1] = info + '0';
	strcpy(nu->info,text);
	
	if(p==1)
	{
		nu->link=start;
		start=nu;
		return;
	}
	while(ptr!=NULL)
	{
		c++;
		if(c==p)
		break;
		prev=ptr;
		ptr=ptr->link;
	}
	if(p>c+1)
	{
		printf("\nInvalid position");
		return;
	}
	nu->link=ptr;
	prev->link=nu;
}


void del_from_posi(int p) //Method to delete node from the desired position
{
	N *ptr,*prev;int c=0;
	if(start==NULL)
	{
		printf("\nEmpty");
		return;
	}
	ptr=prev=start;
	while(ptr!=NULL)
	{
		c++;
		if(c==p)
		break;
		prev=ptr;
		ptr=ptr->link;
	}
	if(p>c)
	{
		printf("\nInvalid position");
		return;
	}
	if (ptr==start)
	start=start->link;
	else
	prev->link=ptr->link;
	//printf("\nDeleted node's size =%d and its starting address was %d\n\n",ptr->size,ptr->start_address);
	free(ptr);
}


void display() //Method to display the linked list
{
	N *ptr=start;
	//printf("The linked list:\n\n");
	if(start==NULL)
	{
		printf("Empty");
		return;
	}
	while (ptr->link!=NULL)
	{
		printf("(%s, %d, %d KB) -->",ptr->info,ptr->start_address,ptr->size);
		ptr=ptr->link;
	}
	printf("(%s, %d, %d KB)",ptr->info,ptr->start_address,ptr->size);
}


void First_Fit(int n, int *requests) //Method to implement First-fit
{
	int i, c;
	N *ptr;
	for(i=1; i <= n; i++)
	{
		c = 0;
		ptr = start;
		while(ptr->link != NULL)
		{
			c++;
			if(requests[i] <= ptr->size && (strcmp(ptr->info,"Hole") == 0))
			{
				printf("\n\nProcess %d allocated to partition %s with starting address %d\n\n",i,ptr->info,ptr->start_address);
				ptr->size -= requests[i];
				insert_at_posi(c+1,ptr->start_address,ptr->size,requests[i],i);
				if(ptr->size == 0)
				del_from_posi(c);
				display();
				printf("\n\n");
				break;
			}
			ptr = ptr->link;
		}
	}
	printf("\nAfter applying First Fit the final condition of the memory is:\n\n");
	display();
}


int Min_Hole() //Method to find out the hole with minimum size required for Best-fit
{
	N *ptr = start;
	int min = 10000, pos = 0, p = 0;
	while(ptr->link != NULL)
	{
		p++;
		if(ptr->size < min && (strcmp(ptr->info,"Hole") == 0))
		{
			min = ptr->size;
			pos = p;
		}
		ptr = ptr->link;
	}
	return pos;
}

void Best_Fit(int n, int *requests) //Method to implement Best-fit
{
	int pos;
	
	int i, c;
	N *ptr;
	for(i = 1; i <= n; i++)
	{
		c = 0;
		ptr = start;
		pos = Min_Hole();
		printf("\nThe node number of the hole with minimum size is %d\n",pos);
		while(ptr->link != NULL)
		{
			c++;
			if((c == pos) && requests[i] <= ptr->size && (strcmp(ptr->info,"Hole") == 0))
			{
				printf("\n\nProcess %d allocated to partition %s with starting address %d\n\n",i,ptr->info,ptr->start_address);
				ptr->size -= requests[i];
				insert_at_posi(c+1,ptr->start_address,ptr->size,requests[i],i);
				if(ptr->size == 0)
				del_from_posi(c);
				display();
				printf("\n\n");
				break;
			}
			ptr = ptr->link;
		}
	}
	printf("\nAfter applying Best Fit the final condition of the memory is:\n\n");
	display();
}


int Max_Hole() //Method to find out the hole with maximum size required for Worst-fit
{
	N *ptr = start;
	int max = 0, pos = 0, p = 0;
	while(ptr->link != NULL)
	{
		p++;
		if(ptr->size > max && (strcmp(ptr->info,"Hole") == 0))
		{
			max = ptr->size;
			pos = p;
		}
		ptr = ptr->link;
	}
	return pos;
}


void Worst_Fit(int n, int *requests) //Method to implement Worst-fit
{
	int pos;
	
	int i, c;
	N *ptr;
	for(i = 1; i <= n; i++)
	{
		c = 0;
		ptr = start;
		pos = Max_Hole();
		printf("\nThe node number of the hole with maximum size is %d\n",pos);
		while(ptr->link != NULL)
		{
			c++;
			if((c == pos) && requests[i] <= ptr->size && (strcmp(ptr->info,"Hole") == 0))
			{
				printf("\n\nProcess %d allocated to partition %s with starting address %d\n\n",i,ptr->info,ptr->start_address);
				ptr->size -= requests[i];
				insert_at_posi(c+1,ptr->start_address,ptr->size,requests[i],i);
				if(ptr->size == 0)
				del_from_posi(c);
				display();
				printf("\n\n");
				break;
			}
			ptr = ptr->link;
		}
	}
	printf("\nAfter applying Worst Fit the final condition of the memory is:\n\n");
	display();
}

int main()
{
	int n, requests[10], i, ch;
	printf("Present condition of the memory is:\n\n");
	insert_at_end("A",0,50);
	insert_at_end("Hole",50,75);
	insert_at_end("B",125,100);
	insert_at_end("Hole",225,175);
	insert_at_end("C",400,300);
	display();
	printf("\n\nEnter the number of processes in the queue:\n");
	scanf("%d",&n);
	printf("\nEnter the requests of the processes:\n");
	for(i = 1; i <= n; i++)
	{
		scanf("%d",&requests[i]);
	}
	printf("The processes in the queue and their requests are:\n");
	for(i = 1; i <= n; i++)
	{
		printf("Process no: %d\t Request: %d KB\n",i,requests[i]);
	}

	printf("\n\nEnter 1 to apply First Fit\nEnter 2 to apply Best Fit\nEnter 3 to apply Worst Fit\n");
	printf("Enter your choice:\n");
	scanf("%d",&ch);
	printf("\n\nInitial condition of the memory is:\n\n");
	display();
	printf("\n");
	switch(ch)
	{
		case 1: First_Fit(n,requests);
		break;
		case 2: Best_Fit(n,requests);
		break;
		case 3: Worst_Fit(n,requests);
		break;
		default: printf("Wrong choice");
	}
	return 0;
}
