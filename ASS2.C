#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#define SIZE 5

int push(int [],int);
int pop(int [],int);
void show(int [],int);
void modify(int [],int);
void peep(int [],int);
int main()
{
    int choice;
    int top = -1,stack[SIZE];
    clrscr();
    while (1)
    {

	printf("\nPerform operations on the stack:");
	printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.modify \n5.End\n6.peep");
	printf("\n\nEnter the choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	    top=push(stack,top);
	    break;
	case 2:
	    top=pop(stack,top);
	    break;
	case 3:
	    show(stack,top);
	    break;
	case 4:
	    modify(stack,top);
	    break;
	case 6:
	    peep(stack,top);
	    break;
	case 5:
	     exit(0);
	default:
	    printf("\nInvalid choice!!");
	}
	getch();
    }
}
int push(int stack[],int top)
{
    int x;
    if (top == SIZE - 1)
    {
	printf("\nOverflow!!");
    }
    else
    {
	printf("\nEnter the element to be added into the stack: ");
	scanf("%d", &x);
	top = top + 1;
	stack[top] = x;
    }
    return top;
}
int pop(int stack[],int top)
{
    if (top == -1)
    {
	printf("\nUnderflow!!");
    }
    else
    {
	printf("\nPopped element: %d", stack[top]);
	top = top - 1;
    }
    return top;
}
void show(int stack[],int top)
{   int i;
    if (top == -1)
    {
	printf("\nUnderflow!!");
    }
    else
    {
	printf("\nElements present in the stack: \n");
	for ( i = top; i >= 0; --i)
	    printf("%d\n", stack[i]);
    }
}
void modify(int stack[],int top)
{
	int ele;
	if(top==-1)
	{
		printf("stack is empty\n");
		return;
	}
	printf("enter new element:\n");
	scanf("%d",&ele);
	stack[top]=ele;
	printf("element modify successfully");

}
void peep(int stack[],int top)
{
	if(top==-1)
	{
		printf("stack is empty.can not peep");
		return;
	}
	printf("top element:%d\n",stack[top]);
}
