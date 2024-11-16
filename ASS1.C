//write a menu driven program to implement operations on array.
//1]add 2]delete 3]modify 4]sort 5]simple search 6]binary search.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
int arr[10];
int top=-1;
void insert_element(int n)
{
    if(top==9)
    {
	printf("\nSorry we can't insert the value. Array is full.\nDelete element for inserting a value.");
    }
    else if(isalpha(n))
    {
	printf("\nYou can't enter alphanumeric value in the array.");
	return;
    }
    else if(n>=0)
    {
	top++;
	arr[top]=n;
    }
    else
    {
	printf("\nYou can't enter special case letters in the array.");
	return;
    }
}
void delete_element(int n)
{
    int i,found=0;
    for(i=0;i<=top;i++)
    {
		
	if(arr[i]==n)
	{
		found=1;
		printf("delete element");
		break;
	}
    }
    if(found)
    {
	for(i=0;i<top;i++)
	{
		arr[i]=arr[i+1];
	}
	top--;
    }
    else
    {
	printf("element not found");
    }
}
void display()
{
    int i;
    if(top==-1)
    {
	printf("\nArray is empty.");
    }
    else
    {
	 for(i=0; i<=top; i++)
	{
	    printf("\n%d", arr[i]);
	}
    }
}
void modify_element(int ele, int  nele)
{


    int i,found=0;
    for(i=0;i<=top;i++)
    {
	if(arr[i]==ele)
	{
		found=1;
		arr[i]=nele;
		break;
	}
    }
    if(!found)
    {
	printf("element not found");
    }

}
void sort()
{
    int i, temp, j;
     if(top==-1)
    {
	printf("\nArray is empty.");
    }
    else
    {
	for(i=0; i<=top; i++)
	{
	    for(j=i; j<=top; j++)
	    {
		if(arr[j]<arr[i])
		{
		    temp=arr[i];
		    arr[i]=arr[j];
		    arr[j]=temp;
		}
	    }
	}
	printf("\nSorted Array is: ");
       display();
    }
}
void simple_search(int ele)
{
    /*int i, flag=0;
    if(top==-1)
    {
	printf("\nArray is empty.");
    }
    else
    {
	for(i=0; i<=top; i++)
	{
	    if(arr[i]==ele)
	    {
		printf("\nFound on position %d.", i+1);
		flag=1;
	    }
	}
	if(flag==0)
	{
	    printf("\nNo such element %d.", ele);
	}
    }                   */
    int i;
    for(i=0;i<=0;i++)
    {
	if(arr[i]==ele)
	{
		printf("\n search ele success ",&ele);
	}
	else
	{
		printf("\n no element found");
	}
    }
}
int binary_search(int ele)
{
    int low=0,high=top,mid;
 //   sort();
    while(low<=high)
    {
	mid=(low+high)/2;
	if(arr[mid]==ele)
	{
		return mid;

	}
	else if(arr[mid]<ele)
	{
		low=mid+1;
		printf("element found..");
	}
	else
	{
		high=mid-1;
	}
    }
	return -1;
}

int main()
{
    int choice, ele, nele;
    do{

	printf("\n1]Add\n2]Delete\n3]Modify\n4]Sort\n5]Search element with SIMPLE SEARCH.\n6]Search element with BINARY SERACH.\n7]Display\n8]Exit.");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	if(!isdigit(choice))
	{
	    switch (choice)
	    {
		 clrscr();
		case 1:
		printf("\nEnter element: ");
		scanf("%d", &ele);
		insert_element(ele);
		break;

	    case 2:
		printf("\nEnter element you want to delete: ");
		scanf("%d", &ele);
		delete_element(ele);
		break;

	    case 3:
		printf("\nEnter the element you want to modify: ");
		scanf("%d", &ele);
		printf("\nEnter new element: ");
		scanf("%d", &nele);
		modify_element(ele, nele);
		break;

	    case 4:
		sort();
		break;

	    case 5:
		printf("\nEnter element you want to search: ");
		scanf("%d", &ele);
		simple_search(ele);
		break;

	    case 6:
		printf("\nEnter element you want to search: ");
		scanf("%d", &ele);
		binary_search(ele);
		break;

	    case 7:
		display();
		break;

	    case 8:
		exit(1);

	    default:
		printf("\nWrong choice.");
		break;
	    }
	}
	else
	{
		printf("\nYou can't enter special case letters and string values.");
	}
    }while(1);
    return 0;
}