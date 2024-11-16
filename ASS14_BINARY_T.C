#include<stdio.h>
#include<stdlib.h>

struct treenode
{
    struct treenode *lptr;
    int data;
    struct treenode *rptr;
};
void ins_bin_tree(struct treenode **root, int ele)
{
    struct treenode *curr, *prev, *new;
    new = (struct treenode*)malloc(sizeof(struct treenode));
    prev = NULL;
    curr = *root;

    new->data = ele;
    new->lptr = NULL;
    new->rptr = NULL;

   if(*root == NULL)
   {
	*root = new;
	return;
    }
    while (curr != NULL)
    {
		prev = curr;
		if (new->data < curr->data)
		{
	 		curr = curr->lptr;
		}
		else
		{
	    	curr = curr->rptr;
		}
    }
    if (new->data < prev->data)
     {
		prev->lptr = new;
     }
     else
     {
		prev->rptr = new;
     }
}
void inorder(struct treenode *curr) {
    if (curr == NULL)
    {
	return;
    }
    else
    {
	inorder(curr->lptr);
	printf("%d ", curr->data);
	inorder(curr->rptr);
    }
}
void preorder(struct treenode *curr)
{
	if(curr==NULL)
	{
		return;
	}
	printf("%d ", curr->data);
	preorder(curr->lptr);
	preorder(curr->rptr);
}
void postorder(struct treenode *curr)
{
	if(curr==NULL)
	{
		return;
	}
	else
	{
		postorder(curr->lptr);
		postorder(curr->rptr);
		printf("%d ", curr->data);
	}
}
void main()
{
    struct treenode *root = NULL;
    int ele, choice;

    while (1)
    {
	printf("\n1. Insert\n2. In-order\n3.pre-order\n4.post-order\n5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	 {
	    case 1:
		printf("Enter value: ");
		scanf("%d", &ele);
		ins_bin_tree(&root, ele);
		break;
	    case 2:
		if (root == NULL)
		{
		    printf("tree is empty.\n");
		}
		 else
		{
		    printf("In-order traverse: ");
		    inorder(root);
		}
		break;
		case 3:
		if(root==NULL)
		{
			printf("tree is empty\n");
		}
		else
		{
			printf("preorder traverse: ");
			preorder(root);
		}
		break;
		case 4:
		if(root==NULL)
		{
			printf("tree is empty\n");
		}
		else
		{
			printf("post-order traverse: ");
			postorder(root);
		}
		break;
	    case 5:
		exit(0);
	    default:
		printf("invalid choice.\n");
	}
    }
}
