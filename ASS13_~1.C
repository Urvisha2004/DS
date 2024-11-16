
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};

void insert_d_c_ll(struct node **head, int ele) {
    struct node *new, *curr, *prev;
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new->data = ele;

    if (*head == NULL) {
        // List is empty
        new->next = new;
        new->prev = new;
        *head = new;
    } else {
        curr = *head;
        prev = NULL;

        while (curr->data < ele && curr->next != *head) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            new->next = *head;
            new->prev = (*head)->prev;
            (*head)->prev->next = new;
            (*head)->prev = new;
            *head = new;
        } else {
            new->next = curr;
            new->prev = prev;
            curr->prev = new;
            prev->next = new;
        }
    }
}

void delete(struct node **head, int ele)
 {
    struct node *curr = *head;
    if (*head == NULL) {
	printf("List is empty\n");
	return;
    }




    do {
	if (curr->data == ele) {
	    if (curr->next == curr && curr->prev == curr) {
                // Only one node in the list
                free(curr);
                *head = NULL;
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                if (curr == *head) {
                    *head = curr->next;
                }
                free(curr);
            }
            printf("Element %d deleted\n", ele);
            return;
        }
        curr = curr->next;
    } while (curr != *head);

    printf("Element %d not found\n", ele);
}

void display(struct node *head) {
    struct node *curr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

void modify(struct node *head, int old_ele, int new_ele) {
    struct node *curr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        if (curr->data == old_ele) {
            curr->data = new_ele;
            printf("Element %d modified to %d\n", old_ele, new_ele);
            return;
        }
        curr = curr->next;
    } while (curr != head);

    printf("Element %d not found\n", old_ele);
}

void main()
{
    struct node *head = NULL;
    int choice, ele, old_ele, new_ele;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Modify\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

	switch (choice)
	{
	    case 1:
		printf("Enter element to insert: ");
		scanf("%d", &ele);
		insert_d_c_ll(&head, ele);
		break;
	    case 2:
		printf("Enter element to delete: ");
		scanf("%d", &ele);
		delete(&head, ele);
		break;
	    case 3:
		display(head);
		break;
	    case 4:
		printf("Enter element to modify: ");
		scanf("%d", &old_ele);
		printf("Enter new value: ");
		scanf("%d", &new_ele);
		modify(head, old_ele, new_ele);
		break;
	    case 5:
		exit(0);
	    default:
		printf("Invalid choice\n");
	}
    }
}
