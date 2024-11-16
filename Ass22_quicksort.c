#include<stdio.h>
void quicksort(int[],int,int);
int main()
{
    int i,n,a[10];
    printf("enter size of array(max 10): \n");
    scanf("%d",&n);

    if (n < 1 || n > 10) {
        printf("Invalid size. Please enter a value between 1 and 10.\n");
        return 1;
    }

    printf("enter element of array: ");

    for(i=0;i<n;i++)
    {
        scanf("%d ",&a[i]);

    }
    printf("\n befor sorting element : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    quicksort(a,0,n-1);
    printf("\nafter sortiting : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void quicksort(int a[],int first,int last)
{
    int i,j,key,temp;
    if(first<last)
    {
        key=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[key]&&i<last)
            {
                i++;
            }
            while(a[j]>a[key])
            {
                j--;
            }
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[key];
        a[key]=a[j];
        a[j]=temp;
        quicksort(a,first,j-1);
        quicksort(a,j+1,last);
    }
}