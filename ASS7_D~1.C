
//Pro :-4. Write a menu driven program to implement double Queue  1) Insert 2) Delete 3) Display.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 10
int q[max];
void main()
{

	void insert_doub_que( int * , int * ,int * , int * , int );
	void delete_doub_que( int * , int *,int * , int *  );
	void display_doub_que( int *,int *,int * , int * );
	void modify_doub_que(int *,int *,int *,int *,int );
	int *front1 , *rear1,*front2 , *rear2;

	int ele,choice , pop_val;

	front1= (int *)malloc(sizeof(int *));
	rear1 = (int *)malloc(sizeof(int *));
	front2= (int *)malloc(sizeof(int *));
	rear2 = (int *)malloc(sizeof(int *));

	*(front1) = -1;
	*(front2) = max;
	*(rear1) = -1;
	*(rear2) = max;

	while(1)
	{
		printf("\n 1.Insert Value :-  ");
		printf("\n 2. Delete  Value :- ");
		printf("\n 3. Display Value :-");
		printf("\n 4. modify value:-");
		printf("\n 5. Exit Program :-");

		printf("\n Enter Your Choice :- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:{
				printf("\n Enter Front Value :");
				scanf("%d",&ele);
				insert_doub_que(front1,rear1,front2,rear2,ele);
				break;
			}
			case 2:{
				delete_doub_que(front1,rear1,front2,rear2);
				break;
			}
			case 3:{
				display_doub_que(front1,rear1,front2,rear2);
				break;
			}
			case 4:{
				modify_doub_que(front1,rear1,front2,rear2,ele);
				break;
			}

			case 5:{
				exit(1);
				break;
			}

		}

	}

}

void insert_doub_que( int *front1, int * rear1, int * front2, int  *rear2, int ele)
{
	int choice;

	if(*(front1)==*(front2)-1 && *(front2)==*(front1)+1)
	{
		printf("\n Double Queue is Full...");
	}
	else
	{
		printf("\n 1.Insert Front Queue :- \n 2.Insert End side Queue :-\n 3. Exit :-");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:{
				if(*(front1)==-1 && *(rear1)==-1)
				{
					*(front1)=*(rear1)=0;
					q[*(front1)]=ele;
				}
				else
				{
					*(front1)=*(front1) + 1;
					q[*(front1)]=ele;
				}
				break;
			}
			case 2 :{
				if(*(front2)== max && *(rear2)== max)
				{
					*(front2)=*(rear2)=max-1;
					q[*(front2)]=ele;
				}
				else
				{
					*(front2)=*(front2) - 1;
					q[*(front2)]=ele;
				}
				break;
			}
		}
	}

}
void delete_doub_que( int * front1 ,int * rear1, int * front2, int  *rear2 )
{
	int choice ;
	if(*(front1)==-1 && *(front2)== max)
	{
		printf("\n Double Queue is Empty...");
	}
	else
	{
		printf("\n 1.Delete Front Queue :- \n 2.Delete End side Queue :-\n 3. Exit :-");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:{
				if(*(front1)==-1 && *(rear1)==-1)
				{
					printf("\n Front Delete Queue is Empty...");
				}
				else
				{
					if(*(rear1)==*(front1))
					{
						printf("\n Front Delete Queue is :-  %d ",q[*(rear1)]);
						*(rear1)=*(front1)=-1;
					}
					else
					{
						printf("\n Front Delete Queue is :-  %d ",q[*(rear1)]);
						*(rear1)=*(rear1) + 1;
					}
				}
				break;
			}
			case 2 :{
				if(*(front2)==max && *(rear2)==max)
				{
					printf("\n End Side Delete Queue is Empty...");
				}
				else
				{
					if(*(rear2)==*(front2))
					{
						printf("\n End Side Delete Queue is :-  %d ",q[*(rear2)]);
						*(rear2)=*(front2)=max;
					}
					else
					{
						printf("\n End Side Delete Queue is :-  %d ",q[*(rear1)]);
						*(rear2)=*(rear2) - 1;
					}
				}
				break;
			}
		}
	}
}
void display_doub_que( int * front1 ,int * rear1, int * front2, int  *rear2)
{
	int choice ,i,j ;
	if(*(front1)==-1 && *(front2)== max)
	{
		printf("\n Double Queue is Empty...");
	}
	else
	{
		printf("\n 1.Display Front to End Side Queue :- \n 2.Display End side to Front Queue :-\n 3. Exit :-");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:{
				if(*(front1)==-1 )
				{
					printf("\n Front Display Queue is Empty...");
				}
				else
				{
					for(i=*(rear1) ; i<= *(front1) ; i++)
					{
						printf("\n Front to End Side Display is  :- %d ",q[i]);
					}
				}
				if(*(front2)== max )
				{
					printf("\n End Side Display Queue is Empty...");
				}
				else
				{
					for(j=*(rear2) ; j>= *(front2) ; j--)
					{
						printf("\n Front to End Side Display is  :- %d ",q[j]);
					}
				}
				break;
			}
			case 2 :{
				if(*(front2)== max )
				{
					printf("\n End Side Display Queue is Empty...");
				}
				else
				{
					for(j=*(rear2) ; j>= *(front2) ; j--)
					{
						printf("\n Front to End Side Display is  :- %d ",q[j]);
					}
				}
				if(*(front1)==-1 )
				{
					printf("\n Front Display Queue is Empty...");
				}
				else
				{
					for(i=*(front1) ; i>= *(rear1) ; i--)
					{
						printf("\n Front to End Side Display is  :- %d ",q[i]);
					}
				}
				break;
			}
		}
	}
}
//void modify_doub_que( int * front1 ,int * rear1, int * front2, int  *rear2,int ele )
//{
/*int choice;
	if(*(front1)==-1 && *(front2)== max)
	{
		printf("\n Double Queue is Empty...");
	}
	else
	{
		printf("\n 1.modify Front Queue :- \n 2.modify End side Queue :-\n 3. Exit :-");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:{
				if(*(front1)==-1 && *(rear1)==-1)
				{
					printf("enter new element\n");
					scanf("%d",&ele);
					q[*front1]=ele;
					printf("modify first element:");

				}
				}
				case 2:
				{
					if(*(front2)==-1&&*(rear2)==-1)
					{
						printf("enter new element:\n");
						scanf("5d",&ele);
						q[*front2]=ele;
						printf("modify second element..");
					}
				}
			}

} */
 /*int choice;

    if (front1 == -1 && front2 == max)
    {
	printf("\nDouble Queue is Empty...");
	return;
    }

    printf("\n1. Modify Front Queue");
    printf("\n2. Modify End Side Queue");
    printf("\nEnter Your Choice: ");
    scanf("%d", &choice);

    if (choice == 1 && front1 != -1)
     {
	printf("\nEnter New Value to Modify Front Queue: ");
	scanf("%d", &ele);
	q[rear1] = ele;
    }
    else if (choice == 2 && front2 != max)
    {
	printf("\nEnter New Value to Modify End Side Queue: ");
	scanf("%d", &ele);
	q[rear2] = ele;
    }
    else
    {
	printf("\nInvalid Choice or Queue is Empty!");
    }
}*/
void modify_doub_que(int *front1, int *rear1, int *front2, int *rear2, int ele)
{
    int choice;

    if (*front1 == -1 && *front2 == max)
    {
	printf("\nDouble Queue is Empty...");
	return;
    }

    printf("\n1. Modify Front Queue");
    printf("\n2. Modify End Side Queue");
    printf("\nEnter Your Choice: ");
    scanf("%d", &choice);

    if (choice == 1 && *front1 != -1)
    {
	printf("\nEnter New Value to Modify Front Queue: ");
	scanf("%d", &ele);
	q[*front1] = ele;
    }
    else if (choice == 2 && *front2 != max)
    {
	printf("\nEnter New Value to Modify End Side Queue: ");
	scanf("%d", &ele);
	q[*front2] = ele;
    }
    else
    {
	printf("\nInvalid Choice or Queue is Empty!");
    }
}