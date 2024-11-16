#include<stdio.h>
#include<conio.h>
#define max1 5
#define max2 5
int q1[max1],q2[max2];
int f1=-1;
int r1=-1;
int f2=-1;
int r2=-1;
void insert();
void delete();
void display();
void main()
{
	clrscr();

	while(1)
	{       int ch;

		printf("\n1.push\n2.pop\n3.display1\n4.exit");
		printf("\n enter your choice:");
		scanf("\n %d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("invalid choice");

		}
	}
}
void insert()
{
	int x;
	printf("insert the element in queue");
	scanf("%d",&x);
	if(x>=60)
	{
		if(r1==max1-1)
		{
			printf(" max queue is full");
		}
		else
		{
			if(f1==-1&&r1==-1)
			{
				f1=r1=0;
				q1[r1]=x;
			}
			else
			{
				r1++;
				q1[r1]=x;
			}
		}
	}
	else
	{
		if(r2==max2-1)
		{
			printf(" low queue is full");
		}
		else
		{
			if(f2==-1&&r2==-1)
			{
				f2=r2=0;
				q2[r2]=x;
			}
			else
			{
				r2++;
				q2[r2]=x;
			}
		}
	}
}
void delete()
{
	if(r1>=60)
	{
		if(f1<=r1)
		{
			printf("%d is delete q1\n",q1[f1]);
			f1=f1+1;
		}
		else
		{
			if(f2<=r2)
			{
			printf("%d is delete q2\n",q2[f2]);
			f2=f2+1;
			}
		}
	}
	else
	{
		if(f2<=r2)
		{
			printf("%d delete q2\n",q2[f2]);
			f2=f2+1;
		}
	}
}
void display()
{

    int i1, i2;

    printf("\nHigh Priority Queue (q1):\n");
    if (f1 == -1) {
	printf("Empty\n");
    } else {
	for (i1 = f1; i1 <= r1; i1++) {
	    printf("%d ", q1[i1]);
	}
	printf("\n");
    }

    printf("\nLow Priority Queue (q2):\n");
    if (f2 == -1) {
	printf("Empty\n");
    } else {
	for (i2 = f2; i2 <= r2; i2++) {
	    printf("%d ", q2[i2]);
	}
	printf("\n");
    }
}