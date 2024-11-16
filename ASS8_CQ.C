#include <stdio.h>
#include <stdlib.h>

#define max 5

void insert(int cq[], int *f, int *r, int ele);
int delete(int cq[], int *f, int *r);
void display(int cq[], int *f, int *r);
void modify(int cq[], int *f, int *r, int ele, int nele);
int main()
 {
    int front = -1, rear = -1, cq[max], ch, ele,nele;
    int *f = &front, *r = &rear;

    while(1)
    {
	printf("\n1. Insert");
	printf("\n2. Delete");
	printf("\n3. Display");
    printf("\n5.modify");
	printf("\n4. Exit");
	printf("\nEnter choice: ");
	scanf("%d", &ch);

	switch(ch)
	 {
	    case 1:
		printf("Enter element to insert: ");
		scanf("%d", &ele);
		insert(cq, f, r, ele);
		break;
	    case 2:
		ele = delete(cq, f, r);
		if (ele != -1)
		{
		    printf("Deleted element: %d\n", ele);
		}
		break;
	    case 3:
		display(cq, f, r);
		break;
	    case 5:
	     printf("Enter the element to modify: ");
	    scanf("%d", &ele);
	    printf("Enter the new element: ");
	    scanf("%d", &nele);
	    modify(cq,f,r,ele,nele);
	    break;
	    case 4:
		exit(0);
	    default:
		printf("Invalid choice!\n");
	}
    }

    return 0;
}

void insert(int cq[], int *f, int *r, int ele)
{
    if ((*r + 1) % max == *f)
     {
	printf("Queue is full\n");
	return;
    }

    if (*f == -1 && *r == -1)
    {
	*f = *r = 0;
    } else {
	*r = (*r + 1) % max;
    }
    cq[*r] = ele;
}

int delete(int cq[], int *f, int *r)
{
    int removed_ele;

    if (*f == -1)
    {
	printf("Queue is empty\n");
	return -1;
    }

    removed_ele = cq[*f];
    if (*f == *r)
    {
	*f = *r = -1;
    } else
    {
	*f = (*f + 1) % max;
    }

    return removed_ele;
}

void display(int cq[], int *f, int *r)
{
    int i;

    if (*f == -1)
     {
	printf("Queue is empty\n");
	return;
    }

    printf("Queue elements: ");
    for (i = *f; i != *r; i = (i + 1) % max)
    {
	printf("%d ", cq[i]);
    }
    printf("%d\n", cq[i]);
}
void modify(int cq[], int *f, int *r, int ele, int nele)
 {  int i;
    if (*f == -1)
     {
	printf("Circular Queue is empty\n");
	return;
    }


    if (*r >= *f) {
	for ( i = *f; i <= *r; i++) {
	    if (cq[i] == ele)
	    {
		cq[i] = nele;
		printf("Modified element %d to %d\n", ele, nele);
		break;
	    }
	}
    } else {
	for ( i = *f; i < max; i++)
	{
	    if (cq[i] == ele)
	    {
		cq[i] = nele;
		printf("Modified element %d to %d\n", ele, nele);

		break;
	    }

    }
}
}
