#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_ll(struct node **head, int val);
void delete_link(struct node **head, int search);
void modify_link(struct node **head, int old_val, int new_val);
void display_link(struct node **head);

 void main() {
    struct node *head = NULL;
    int val, search, old_val, new_val;
    int choice;

    while(1) {
        printf("\n1. Insert");
        printf("\n2. Search and Delete");
        printf("\n3. Modify");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &val);
                insert_ll(&head, val);
                break;
            case 2:
                printf("\nEnter value to delete: ");
                scanf("%d", &search);
                delete_link(&head, search);
                break;
            case 3:
                printf("\nEnter value to modify: ");
                scanf("%d", &old_val);
                printf("Enter new value: ");
                scanf("%d", &new_val);
                modify_link(&head, old_val, new_val);
                break;
            case 4:
                display_link(&head);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }


}

void insert_ll(struct node **head, int val)
 {
    struct node *new_node ;
    new_node= (struct node *)malloc(sizeof(struct node));
    if (!new_node)
    {
	printf("Memory allocation failed\n");
	return;
    }

    new_node->data = val;

    if (*head == NULL)
     {
	new_node->next = new_node;
	*head = new_node;
     }
     else
     {
	struct node *temp = *head;
	while (temp->next != *head)
	    temp = temp->next;
	temp->next = new_node;
	new_node->next = *head;
    }
}

void delete_link(struct node **head, int search) {
 struct node *curr = *head, *prev = NULL;
    if (*head == NULL)
    {
	printf("\nLinked List is empty\n");
	return;
    }
    if (curr->data == search)
     {
	if (curr->next == *head)
	 {
	    free(curr);
	    *head = NULL;
	    printf("\nDeleted value: %d\n", search);
	    return;
	 }
	else
	 {
	    while (curr->next != *head)
		curr = curr->next;
	    curr->next = (*head)->next;
	    printf("\nDeleted value: %d\n", (*head)->data);
	    free(*head);
	    *head = curr->next;
	    return;
	}
    }

    // Search for the node to delete
    curr = *head;
    do {
        prev = curr;
        curr = curr->next;
    } while (curr != *head && curr->data != search);

    if (curr == *head) {
        printf("\nElement not found\n");
    } else {
        prev->next = curr->next;
        printf("\nDeleted value: %d\n", curr->data);
        free(curr);
    }
}

void modify_link(struct node **head, int old_val, int new_val) {
    struct node *curr = *head;
    if (*head == NULL) {
        printf("\nLinked List is empty\n");
        return;
    }
    do {
        if (curr->data == old_val) {
            curr->data = new_val;
            printf("\nModified value from %d to %d\n", old_val, new_val);
            return;
        }
        curr = curr->next;
    } while (curr != *head);

    printf("\nElement not found\n");
}

void display_link(struct node **head) {
   struct node *curr = *head;
    if (*head == NULL) {
        printf("\nLinked List is empty\n");
        return;
    }


    do {
	printf("\nValue: %d", curr->data);
	curr = curr->next;
    } while (curr != *head);
    printf("\n");
}
