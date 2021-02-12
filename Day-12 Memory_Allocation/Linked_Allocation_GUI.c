//C program to develop a GUI application for Memory Allocation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define BLACKONYELLOW 6

typedef struct node
{
	char info[50];
	int start_address;
	int size;
	struct node *link;
}N;

N *start;
int colors[5] = {1,2,3,4,5};


void wCenterTitle(WINDOW *pwin, const char * title)
{
    int x, maxy, maxx, stringsize;
    getmaxyx(pwin, maxy, maxx);
    stringsize = 4 + strlen(title);
    x = (maxx - stringsize)/2;
    mvwaddch(pwin, 0, x, ' ');
    waddch(pwin, ' ');
    waddstr(pwin, title);
    waddch(pwin, ' ');
    waddch(pwin, ' ');
}


void wclrscr(WINDOW * pwin)
{
    int y, x, maxy, maxx;
    getmaxyx(pwin, maxy, maxx);
    for(y=0; y < maxy; y++)
        for(x=0; x < maxx; x++)
                mvwaddch(pwin, y, x, ' ');
}


/* Initialize Colors for Curses*/
void Initialize_Colors()
{
	int i;
	start_color();
	
	init_pair(BLACKONYELLOW, COLOR_BLACK, COLOR_YELLOW);

	for(i = 0; i < 5; i++)
	{
		switch(colors[i])
		{
			case 1:
				init_pair(colors[i], COLOR_WHITE, COLOR_RED);
			break;
			case 2:
				init_pair(colors[i], COLOR_WHITE, COLOR_BLUE);
			break;
			case 3:
				init_pair(colors[i], COLOR_WHITE, COLOR_GREEN);
			break;
			case 4:
				init_pair(colors[i], COLOR_WHITE, COLOR_MAGENTA);
			break;
			case 5:
				init_pair(colors[i], COLOR_WHITE, COLOR_CYAN);
			break;
		}
	}
	wrefresh(stdscr);
}

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


void display_curses() //Method to create the Curses window and display information
{
	WINDOW *small_win;
	int i = 0, scale = 0, cols = 6;
	int maxy, maxx;
	char temp[10];
	N *ptr=start;
	
	/* Initialize Curses and refresh the standard screen */
	initscr();
	Initialize_Colors();
	getmaxyx(stdscr, maxy, maxx);
	wrefresh(stdscr);
	
	attron(A_STANDOUT | A_UNDERLINE);
	mvprintw(0,65,"MEMORY ALLOCATION");
	attroff(A_STANDOUT | A_UNDERLINE);
	refresh();
	mvprintw(2,5,"INITIAL CONDITION OF THE MEMORY IS");
	refresh();
	
	if(start==NULL)
	{
		return;
	}
	while (ptr->link!=NULL)
	{
		scale = ptr->size / 4;
		small_win = newwin(10,scale, 17,cols);
		if(strcmp(ptr->info,"Hole") == 0)
		{
			wattrset(small_win, COLOR_PAIR(BLACKONYELLOW) | A_BOLD);
		}
        else
        {
       		wattrset(small_win, COLOR_PAIR(colors[i]) | A_BOLD);	
		}
		
        i = (i + 1)%5;
        
        wclrscr(small_win);
        box(small_win, 0, 0);
        wCenterTitle(small_win, ptr->info);
    	sprintf(temp,"%d",ptr->size);
    	mvwaddstr(small_win, 4,3,temp);
    	mvwaddstr(small_win, 4,7,"KB");
        mvprintw(28,cols,"%d",ptr->start_address);
        
        touchwin(small_win);
        wrefresh(small_win);
	
		cols += scale;
		ptr=ptr->link;
	}
	
	scale = ptr->size / 6;
	small_win = newwin(10,scale, 17,cols);
	if(strcmp(ptr->info,"Hole") == 0)
	{
		wattrset(small_win, COLOR_PAIR(BLACKONYELLOW) | A_BOLD);
	}
    else
    {
       	wattrset(small_win, COLOR_PAIR(colors[i]) | A_BOLD);	
	}
	
    i = (i + 1)%5;
    
    wclrscr(small_win);
    box(small_win, 0, 0);
    wCenterTitle(small_win, ptr->info);
    sprintf(temp,"%d",ptr->size);
    mvwaddstr(small_win, 4,3,temp);
    mvwaddstr(small_win, 4,5,"KB");
    mvprintw(28,cols,"%d",ptr->start_address);
    
    touchwin(small_win);
    wrefresh(small_win);
    wgetch(small_win);
	endwin();
}


void First_Fit(int n, int *requests) //Method to implement First-fit
{
	int i, c , ind = 4;
	N *ptr;
	
	attron(A_STANDOUT | A_UNDERLINE);
	mvprintw(0,65,"MEMORY ALLOCATION USING FIRST FIT");
	attroff(A_STANDOUT | A_UNDERLINE);
	refresh ();
	
	for(i=1; i <= n; i++)
	{
		c = 0;
		ptr = start;
		while(ptr->link != NULL)
		{
			c++;
			if(requests[i] <= ptr->size && (strcmp(ptr->info,"Hole") == 0))
			{
				mvprintw(ind,5,"PROCESS %d ALLOCATED TO PARTITION %s WITH STARTING ADDRESS %d",i,ptr->info,ptr->start_address);
				refresh ();
				ind++;
				
				ptr->size -= requests[i];
				insert_at_posi(c+1,ptr->start_address,ptr->size,requests[i],i);
				if(ptr->size == 0)
				del_from_posi(c);
				display_curses();
				
				break;
			}
			ptr = ptr->link;
		}
	}
	mvprintw(++ind,5,"AFTER APPLYING FIRST FIT THE FINAL CONDITION OF THE MEMORY IS");
	refresh ();

	display_curses();
}


int Min_Hole(int request) //Method to find out the hole with minimum size required for Best-fit
{
	N *ptr = start;
	int min = 10000, pos = 0, p = 0;
	while(ptr->link != NULL)
	{
		p++;
		if((request <= ptr->size) && (ptr->size < min) && (strcmp(ptr->info,"Hole") == 0))
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
	int pos, i, c, ind = 4;
	N *ptr;
	
	attron(A_STANDOUT | A_UNDERLINE);
	mvprintw(0,65,"MEMORY ALLOCATION USING BEST FIT");
	attroff(A_STANDOUT | A_UNDERLINE);
	refresh ();

	for(i = 1; i <= n; i++)
	{
		c = 0;
		ptr = start;
		pos = Min_Hole(requests[i]);
		
		while(ptr->link != NULL)
		{
			c++;
			if((c == pos) && (strcmp(ptr->info,"Hole") == 0))
			{
				mvprintw(ind,5,"PROCESS %d ALLOCATED TO PARTITION %s WITH STARTING ADDRESS %d",i,ptr->info,ptr->start_address);
				refresh ();
				ind++;

				ptr->size -= requests[i];
				insert_at_posi(c+1,ptr->start_address,ptr->size,requests[i],i);
				if(ptr->size == 0)
				del_from_posi(c);
				display_curses();
				
				break;
			}
			ptr = ptr->link;
		}
	}
	mvprintw(++ind,5,"AFTER APPLYING BEST FIT THE FINAL CONDITION OF THE MEMORY IS");
	refresh ();

	display_curses();
}


int Max_Hole(int request) //Method to find out the hole with maximum size required for Worst-fit
{
	N *ptr = start;
	int max = 0, pos = 0, p = 0;
	while(ptr->link != NULL)
	{
		p++;
		if((request <= ptr->size) && (ptr->size > max) && (strcmp(ptr->info,"Hole") == 0))
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
	int pos, i, c, ind = 4;
	N *ptr;
	
	attron(A_STANDOUT | A_UNDERLINE);
	mvprintw(0,65,"MEMORY ALLOCATION USING WORST FIT");
	attroff(A_STANDOUT | A_UNDERLINE);
	refresh ();

	for(i = 1; i <= n; i++)
	{
		c = 0;
		ptr = start;
		pos = Max_Hole(requests[i]);
		
		while(ptr->link != NULL)
		{
			c++;
			if((c == pos) && (strcmp(ptr->info,"Hole") == 0))
			{
				mvprintw(ind,5,"PROCESS %d ALLOCATED TO PARTITION %s WITH STARTING ADDRESS %d",i,ptr->info,ptr->start_address);
				refresh ();
				ind++;

				ptr->size -= requests[i];
				insert_at_posi(c+1,ptr->start_address,ptr->size,requests[i],i);
				if(ptr->size == 0)
				del_from_posi(c);
				display_curses();
				
				break;
			}
			ptr = ptr->link;
		}
	}
	mvprintw(++ind,5,"AFTER APPLYING WORST FIT THE FINAL CONDITION OF THE MEMORY IS");
	refresh ();
	
	display_curses();
}

int main()
{
	int n, requests[10], i, ch;
	
	insert_at_end("A",0,50);
	insert_at_end("Hole",50,75);
	insert_at_end("B",125,100);
	insert_at_end("Hole",225,175);
	insert_at_end("C",400,300);
	
	printf("Enter the number of processes in the queue:\n");
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
	
	display_curses();
	
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
