#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

int queue[5];
int f = -1, r = -1;

void insert(int ele) {
    if ((f==0 && r==4) || r==f-1)
    {
	printf("\nQueue is full. Cannot add process %d.", ele);
    }
    else
    {
	if (f == -1 && r == -1)
	{
	    f = r = 0;
	}
	else if(r==4)
	{
	    r = 0;
	}
	else
	{
	    r++;
	}
	queue[r] = ele;
    }
}

void delete()
{
    if (f == -1 && r == -1)
    {
	printf("\nQueue is empty. No process to remove.");
    }
    else
    {
	printf("\nProcess %d is removed from the queue.", queue[f]);
	if (f == r)
	{
	    f = r = -1;
	}
	else
	{
	   if(f==4)
	   {
		f=0;
	   }
	   else
	   {
		f++;
	   }
	}
    }
}
void display()
{
    int i, j, k;
    if (f == -1 && r==-1)
	{
	printf("\nQueue is empty. No process to display.\n");
    }
    else
    {
	 if(r!=4 && r<f)
	{
	    for(j=0; j<=r; j++)
	    {
		printf("\n%d", queue[j]);
	    }
	    for(k=f; k<=4; k++)
	    {
		printf("\n%d", queue[k]);
	    }
	}
	else
	{
	    for(i=f; i<=r; i++)
	    {
		printf("\n%d", queue[i]);
	    }
	}
    }
}
void main()
{
    char choice[3], ele[3];
    int val_choice, val_ele;
    do
    {
	printf("\n1. Enter Process\n2. Remove Process\n3. Display\n4. Exit\nEnter your choice: ");
	scanf("%s", choice);
	val_choice = atoi(choice);

	if (val_choice == 0)
	{
	    printf("\nOnly numeric values are allowed.");
	}
	else
	{
	    switch (val_choice)
	    {
	    clrscr();
		case 1:
		    printf("\nEnter Process: ");
		    scanf("%s", ele);
		    val_ele = atoi(ele);
		    if (val_ele == 0)
		    {
			printf("\nOnly numeric values are allowed.\n");
		    }
		    else
		    {
			insert(val_ele);
		    }
		    break;
		case 2:
		    delete();
		    break;
		case 3:
		    display();
		    break;
		case 4:
		    exit(0);
		default:
		    printf("\nWrong choice.");
		    break;
	    }
	}
    } while (1);
}