#include<stdio.h>
int getmax(int a[], int n)
{
  int max=a[0];
  for(int i=1;i<n;i++)
  {
    if(a[i]>max)
    {
      max=a[i];
    }

  }
  return max;
}

void sort(int a[], int n,int place)
{
  int data[n];
  int count[10]={0};

  for(int i=0;i<n;i++)
  {
    count[(a[i]/place)%10]++;
  }
  for(int i=1;i<10;i++)
  {
    count[i]+=count[i-1];
  }
  for(int i=n-1;i>=0;i--)
  {
    data[count[(a[i]/place)%10]-1]=a[i];
    count[(a[i]/place)%10]--;
  }
  for(int i=0;i<n;i++)
  {
    a[i]=data[i];
  }

}

void radixsort(int a[],int n)
{
  int max=getmax(a,n);
  for(int place=1;max/place>0;place*=10)
  {
    sort(a,n,place);

  }

}

void printarray(int a[], int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}
int main()
{
  int n;
  printf("enter the number of element: \n ");
  scanf("%d",&n);

  int a[n];

  printf("enter the element: \n");
  for(int i=0;i<n;i++)
  {
    scanf("%d ",&a[i]);
  }
  printf("before sorting : ");
  printarray(a,n);
  radixsort(a,n);
  printf("after sorting :");
  printarray(a,n);
  return 0;
}