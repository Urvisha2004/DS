

#include <stdio.h>
#include<stdlib.h>
#define max 5
void push(int Stack[],int *top1,int *top2)
{
    int choice=0,ele;
    x:
    printf("\n1 For Push in Stack 1 ");
    printf("\n2 For Push in Stack 2 ");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    
    if(choice==1)
    {
        if(*top1==(*top2)-1)
        {
            printf("\nStack is overflow.");
        }
        else
        {
           printf("\nEnter element : ");
           scanf("%d",&ele);
           (*top1)++;
           Stack[*top1]=ele;
           printf("\n%d inserted at index : %d in Stack 1 ",ele,*top1);
        }
    }
    else if(choice==2)
    {
        if(*top2==(*top1)+1)
        {
            printf("\nStack is overflow.");
        }
        else
        {
           printf("\nEnter element : ");
           scanf("%d",&ele);
           (*top2)--;
           Stack[*top2]=ele;
           printf("\n%d inserted at index : %d in Stack 2 ",ele,*top2);
        }
    }
    else
    {
        printf("\nPlease enter correct stack number!.");
        goto x;
    }
}
void pop(int Stack[],int *top1,int *top2)
{
    int stack_choice=0;
    x:
    printf("\n1 For Pop in Stack 1 ");
    printf("\n2 For Pop in Stack 2 ");
    printf("\nEnter your choice : ");
    scanf("%d",&stack_choice);
    
    if(stack_choice==1)
    {
        if((*top1)==-1)
        {
            printf("\nStack 1 is underflow.");
        }
        else
        {
           printf("\n%d Removed from index : %d iin Stack 1.",Stack[*top1],*top1);
           (*top1)--;
        }
    }
    else if(stack_choice==2)
    {
        if((*top2)==max)
        {
            printf("\nStack 2 is underflow.");
        }
        else
        {
          printf("\n%d Removed from index : %d in Stack 2.",Stack[*top2],*top2);
           (*top2)++;
        }
    }
    else
    {
        printf("\nPlease enter correct stack number!.");
        goto x;
    }
}
void peep(int Stack[],int *top1,int *top2)
{
    int stack_choice=0,ele,i,f=0;
    x:
    printf("\n1 For Peep in Stack 1 ");
    printf("\n2 For Peep in Stack 2 ");
    printf("\nEnter your choice : ");
    scanf("%d",&stack_choice);
    
    if(stack_choice==1)
    {
        if(*top1==-1)
        {
            printf("\nStack 1 is underflow.");
        }
        else
        {
            printf("\nEnter element that you want to find : ");
            scanf("%d",&ele);
            for(i=0;i<=(*top1);i++)
            {
                if(Stack[i]==ele)
                {
                    printf("\n%d Found at index : %d in Stack 1.",ele,i);
                    f++;
                }
            }
            if(f==0)
            {
                printf("\nElement not found.");
            }
        }
    }
    else if(stack_choice==2)
    {
        if(*top2==max)
        {
            printf("\nStack 2 is underflow.");
        }
        else
        {
            printf("\nEnter element that you want to find : ");
            scanf("%d",&ele);
            for(i=max-1;i>=(*top2);i--)
            {
                if(Stack[i]==ele)
                {
                    printf("\n%d Found at index : %d in Stack 2.",ele,i);
                    f++;
                }
            }
            if(f==0)
            {
                printf("\nElement not found.");
            }
        }
    }
    else
    {
        printf("\nPlease enter correct stack number!.");
        goto x;
    }
}
void modify(int Stack[],int *top1,int *top2)
{
    int stack_choice=0,ele,i,f=0;
    x:
    printf("\n1 For Modify in Stack 1 ");
    printf("\n2 For Modify in Stack 2 ");
    printf("\nEnter your choice : ");
    scanf("%d",&stack_choice);
    
    if(stack_choice==1)
    {
        if(*top1==-1)
        {
            printf("\nStack 1 is underflow.");
        }
        else
        {
            printf("\nEnter element that you want to Modify : ");
            scanf("%d",&ele);
            for(i=0;i<=(*top1);i++)
            {
                if(Stack[i]==ele)
                {
                    printf("\nEnter new element : ");
                    scanf("%d",&Stack[i]);
                    printf("\n%d replaced for %d in Stack 1.",ele,Stack[i]);
                    f++;
                }
            }
            if(f==0)
            {
                printf("\nElement not found in Stack 1.");
            }
        }
    }
    else if(stack_choice==2)
    {
        if(*top2==max)
        {
            printf("\nStack 2 is underflow.");
        }
        else
        {
            printf("\nEnter element that you want to Modify : ");
            scanf("%d",&ele);
            for(i=max-1;i>=(*top2);i--)
            {
                if(Stack[i]==ele)
                {
                    printf("\nEnter new element : ");
                    scanf("%d",&Stack[i]);
                    printf("\n%d replaced for %d in Stack 2.",ele,Stack[i]);
                    f++;
                }
            }
            if(f==0)
            {
                printf("\nElement not found in Stack 2.");
            }
        }
    }
    else
    {
        printf("\nPlease enter correct stack number!.");
        goto x;
    }
}
void display(int Stack[],int *top1,int *top2)
{
    int stack_choice=0,i;
    x:
    printf("\n1 For Display Stack 1 ");
    printf("\n2 For Display Stack 2 ");
    printf("\nEnter your choice : ");
    scanf("%d",&stack_choice);
    printf("\n");
    if(stack_choice==1)
    {
        if(*top1==-1)
        {
            printf("\nStack 1 is underflow.");
        }
        else
        {
            printf("Stack 1\nIndex : Element ");
            for(i=0;i<=(*top1);i++)
            {
                       printf("\n  %d   :   %d ",i,Stack[i]);
            }
        }
    }
    else if(stack_choice==2)
    {
        if(*top2==max)
        {
            printf("\nStack 2 is underflow.");
        }
        else
        {
           printf("Stack 2\nIndex : Element ");
            for(i=max-1;i>=(*top2);i--)
            {
                   printf("\n  %d   :   %d ",i,Stack[i]);
            }
        }
    }
    else
    {
        printf("\nPlease enter correct stack number!.");
        goto x;
    }
}

int main() {
   int Stack[max],t1=-1,t2=max,*top1=&t1,*top2=&t2,choice;
   while(1)
   {
       printf("\n\n1 For push ");
       printf("\n2 For pop ");
       printf("\n3 For peep ");
       printf("\n4 For modify");
       printf("\n5 For display");
       printf("\n6 For exit");
       printf("\nEnter your choice : ");
       scanf("%d",&choice);
       
       switch(choice)
       {
            case 1:
                push(Stack,top1,top2);
                break;
            case 2:
                pop(Stack,top1,top2);
                break;
            case 3:
                peep(Stack,top1,top2);
                break;
            case 4:
                modify(Stack,top1,top2);
                break;
            case 5:
                display(Stack,top1,top2);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter valid choice");
                break;
       }
   }

    return 0;
}
