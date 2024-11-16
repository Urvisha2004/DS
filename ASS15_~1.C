#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // For clrscr() and getch()

// Structure for the tree node
struct treenode {
    struct treenode *lptr;
    int data;
    struct treenode *rptr;
};

// Function prototypes (declarations)
struct treenode* createNode(int value);
struct treenode* insertIterative(struct treenode* root, int value);
void displayIterative(struct treenode* root);
struct treenode* findMin(struct treenode* node);
struct treenode* deleteNode(struct treenode* root, int key);

// Create a new node
struct treenode* createNode(int value) {
    struct treenode* newNode = (struct treenode*)malloc(sizeof(struct treenode));
    newNode->data = value;
    newNode->lptr = newNode->rptr = NULL;
    return newNode;
}

// Insert a node iteratively
struct treenode* insertIterative(struct treenode* root, int value) {
    struct treenode *newNode = createNode(value);
    if (root == NULL) {
        return newNode;
    }
    
    struct treenode *curr = root;
    struct treenode *parent = NULL;
    
    while (curr != NULL) {
        parent = curr;
        if (value < curr->data) {
            curr = curr->lptr;
        } else {
            curr = curr->rptr;
        }
    }
    
    if (value < parent->data) {
        parent->lptr = newNode;
    } else {
        parent->rptr = newNode;
    }
    
    return root;
}

// Display the tree iteratively (in-order traversal)
void displayIterative(struct treenode* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    
    struct treenode* stack[50];
    int top = -1;
    struct treenode* curr = root;
    
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->lptr;
        }
        
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->rptr;
    }
    printf("\n");
}

// Find the minimum value node in the tree
struct treenode* findMin(struct treenode* node) {
    while (node->lptr != NULL) {
        node = node->lptr;
    }
    return node;
}

// Delete a node from the tree
struct treenode* deleteNode(struct treenode* root, int key) {
    if (root == NULL)
        return root;
    
    if (key < root->data) {
        root->lptr = deleteNode(root->lptr, key);
    } else if (key > root->data) {
        root->rptr = deleteNode(root->rptr, key);
    } else {
        if (root->lptr == NULL) {
            struct treenode* temp = root->rptr;
            free(root);
            return temp;
        } else if (root->rptr == NULL) {
            struct treenode* temp = root->lptr;
            free(root);
            return temp;
        }
        struct treenode* temp = findMin(root->rptr);
        root->data = temp->data;
        root->rptr = deleteNode(root->rptr, temp->data);
    }
    return root;
}

// Main function
int main() {
    struct treenode *root = NULL;
    int value, choice;

    clrscr();  // Clears the screen at the start of the program

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insertIterative(root, value);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Tree elements: ");
                displayIterative(root);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    getch();  // Waits for a key press before closing
    return 0; // Return 0 from main
}
