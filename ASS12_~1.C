#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insert_Circular_link(struct node **, int);
void delete_link(struct node **, int);
void display_link(struct node **);
void modify(struct node **, int, int);

int main() {
	struct node *top = NULL;
	int val, search, new_val;
	int choice;

	while (1) {
		printf("\n1. Insert\n2. Search and Delete\n3. Display\n4. Modify\n5. Exit\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter value to insert: ");
				scanf("%d", &val);
				insert_Circular_link(&top, val);
				break;

			case 2:
				printf("Enter value to delete: ");
				scanf("%d", &search);
				delete_link(&top, search);
				break;

			case 3:
				display_link(&top);
				break;

			case 4:
				printf("Enter value to modify: ");
				scanf("%d", &search);
				printf("Enter new value: ");
				scanf("%d", &new_val);
				modify(&top, search, new_val);
				break;

			case 5:
				exit(0);

			default:
				printf("Invalid choice!\n");
		}
	}
	return 0;
}

void insert_Circular_link(struct node **top, int val) {
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	struct node *curr = *top;
	newnode->data = val;

	if (curr == NULL) {
		newnode->next = newnode;
		*top = newnode;
	} else {
		if (curr->data > val)
		{
			while (curr->next != *top)
			{
				curr = curr->next;
			}
			newnode->next = *top;
			curr->next = newnode;
			*top = newnode;
		} else
		{
			while (curr->next != *top && curr->next->data < val)
			{
				curr = curr->next;
			}
			newnode->next = curr->next;
			curr->next = newnode;
		}
	}
	printf("Value %d inserted.\n", val);
}
void delete_link(struct node **top, int search) {
	struct node *curr = *top, *pre = NULL;

	if (curr == NULL) {
		printf("List is empty.\n");
		return;
	}
	if (curr->data == search)
	{
		if (curr->next == curr)
		{
			free(curr);
			*top = NULL;
		} else
		 {
			while (curr->next != *top)
			{
				curr = curr->next;
			}
			curr->next = (*top)->next;
			free(*top);
			*top = curr->next;
		}
		printf("Value %d deleted.\n", search);
		return;
	}
	pre = *top;
	curr = pre->next;

	while (curr != *top && curr->data != search) {
		pre = curr;
		curr = curr->next;
	}

	if (curr == *top) {
		printf("Value %d not found.\n", search);
	} else {
		pre->next = curr->next;
		free(curr);
		printf("Value %d deleted.\n", search);
	}
}
void display_link(struct node **top) {
	struct node *current = *top;

	if (current == NULL) {
		printf("List is empty.\n");
		return;
	}

	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != *top);

}
void modify(struct node **top, int ele, int new_ele)
 {
	struct node *curr = *top;

	if (curr == NULL) {
		printf("List is empty.\n");
		return;
	}

	do {
		if (curr->data == ele) {
			curr->data = new_ele;
			printf("Value %d modified to %d.\n", ele, new_ele);
			return;
		}
		curr = curr->next;
	} while (curr != *top);

	printf("Value %d not found.\n", ele);
}
