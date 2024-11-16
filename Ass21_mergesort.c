#include<stdio.h>
void merge(int*, int, int, int);
void merge_sort(int*, int, int);

int main()
{
    int a[10],i,n;
    printf("enter number of element in array(max 10)");
    scanf("%d",&n);

    if(n>10||n<1)
    {
        printf("invalid");
        return 1;
    }
    for(i=0;i<n;i++)
    {
        printf("enter element a[%d]:",i);
        scanf("%d",&a[i]);
    }
    printf("array before sorting:\n ");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    merge_sort(a,0,n-1);


    printf("array after sorting: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);

    }
    return 0;
}
void merge_sort(int *a,int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int *a, int low,int mid,int high)
{
    int i=low,j=mid+1,k=low,temp[10];

    while((i<=mid)&&(j<=high))
    {
        if(a[i]<a[j])
        {
            temp[k++]= a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=high)
    {
        temp[k++]=a[j++];
    }
    for(i=low;i<=high;i++)
    {
        a[i]=temp[i];
    }
}