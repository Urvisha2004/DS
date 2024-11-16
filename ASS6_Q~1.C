#include<stdio.h>
#include<conio.h>
#include<conio.h>
void insert(int[],int *,int *);
void delete(int[],int *,int *);
void modify(int[],int *,int *);
void display(int[],int *,int *);
void main()
{
	int front=-1,rear=-1,q[5],ch;
	int *f=&front,*r=&rear;
	while(1)
	{
		printf("\n1.insert");
		printf("\n2.delete");
		printf("\n3.display");
		printf("\n4 modify");
		printf("\n5.exit");
		printf("\nenter choice:");
		scanf("%d",&ch);
		clrscr();
		switch(ch)
		{
			case 1:
			insert(q,f,r);
			break;
			case 2:
			delete(q,f,r);
			break;
			case 3:
			display(q,f,r);
			break;
			case 4:
			modify(q,f,r);
			break;
			case 5:
			exit(0);

		}
	}

}
void insert(int q[],int *f,int *r)
{
	int n;
	if(*r==4)
	{
		printf("\nqueue is overflow");
	}
	else
	{
		if(*f==-1&&*r==-1)
		{
			printf("enter the element");
			scanf("%d",&n);
			*f=*r=0;
			q[*r]=n;

		}
		else
		{
			printf("enter an element:");
			scanf("%d",&n);
			(*r)++;
			q[*r]=n;
		}
	}
}
void delete(int q[],int *f,int *r)
{
	if(*r==-1)
	{
		printf("queue is underflow");

	}
	else
	{
		printf("\n %d is deleted",q[*f]);
		(*f)++;
		if(*f>*r)
		{
			*f=*r=-1;
		}
	}
}

void display(int q[],int *f,int *r)
{
	int i;
	if(*r==-1)
	{
		printf("\n queue is underflow");
	}
	else
	{
		for(i=*f;i<=*r;i++)
		{
			printf("\n %d",q[i]);
		}
	}
}
void modify(int q[],int *f,int *r)
{
	int ele;
	if(*f==-1)
	{
		printf("queue is empty\n");
	}
	printf("enter new element:\n");
	scanf("%d",&ele);
	q[*f]=ele;
	printf("element modify");

}