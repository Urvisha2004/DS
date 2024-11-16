#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the multilink list
struct Node {
    int data;
    struct Node* right; // Pointer to the next element in the row
    struct Node* down;  // Pointer to the next row
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

// Function to add a new row to the multilink list
struct Node* addRow(struct Node* head, int row[], int size) {
    struct Node* newNode = createNode(row[0]);
    struct Node* temp = newNode;

    // Create the rest of the row
    for (int i = 1; i < size; i++) {
        temp->right = createNode(row[i]);
        temp = temp->right;
    }

    // Add the new row to the end of the existing list
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* curr = head;
        while (curr->down != NULL) {
            curr = curr->down;
        }
        curr->down = newNode;
    }
    return head;
}

// Function to display the multilink list
void display(struct Node* head) {
    struct Node* row = head;
    struct Node* col;

    while (row != NULL) {
        col = row;
        while (col != NULL) {
            printf("%d ", col->data);
            col = col->right;
        }
        printf("\n");
        row = row->down;
    }
}

// Function to perform matrix addition
struct Node* matrixAdd(struct Node* matrix1, struct Node* matrix2) {
    struct Node* result = NULL;
    struct Node* row1 = matrix1;
    struct Node* row2 = matrix2;

    while (row1 != NULL && row2 != NULL) {
        struct Node* col1 = row1;
        struct Node* col2 = row2;
        struct Node* newRow = NULL;
        struct Node* temp = NULL;

        while (col1 != NULL && col2 != NULL) {
            int sum = col1->data + col2->data;
            if (newRow == NULL) {
                newRow = createNode(sum);
                temp = newRow;
            } else {
                temp->right = createNode(sum);
                temp = temp->right;
            }
            col1 = col1->right;
            col2 = col2->right;
        }
        
        if (result == NULL) {
            result = newRow;
        } else {
            struct Node* curr = result;
            while (curr->down != NULL) {
                curr = curr->down;
            }
            curr->down = newRow;
        }

        row1 = row1->down;
        row2 = row2->down;
    }
    return result;
}

// Function to perform matrix multiplication
struct Node* matrixMul(struct Node* matrix1, struct Node* matrix2) {
    struct Node* result = NULL;
    struct Node* row1 = matrix1;

    while (row1 != NULL) {
        struct Node* newRow = NULL;
        struct Node* temp = NULL;
        struct Node* col2 = matrix2;

        while (col2 != NULL) {
            int sum = 0;
            struct Node* col1 = row1;
            struct Node* tempCol2 = col2;

            while (col1 != NULL && tempCol2 != NULL) {
                sum += col1->data * tempCol2->data;
                col1 = col1->right;
                tempCol2 = tempCol2->down;
            }

            if (newRow == NULL) {
                newRow = createNode(sum);
                temp = newRow;
            } else {
                temp->right = createNode(sum);
                temp = temp->right;
            }

            col2 = col2->right;
        }

        if (result == NULL) {
            result = newRow;
        } else {
            struct Node* curr = result;
            while (curr->down != NULL) {
                curr = curr->down;
            }
            curr->down = newRow;
        }

        row1 = row1->down;
    }
    return result;
}

int main() {
    struct Node* matrix1 = NULL;
    struct Node* matrix2 = NULL;
    struct Node* result = NULL;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. add row matrix 1\n");
        printf("2. add row matrix 2\n");
        printf("3. display matrix 1\n");
        printf("4. display matrix 2\n");
        printf("5. matrix addition\n");
        printf("6. matrix multiplication\n");
        printf("7. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int row[100];
                int size;
                printf("enter number of element in a row: ");
                scanf("%d", &size);
                printf("ente   elements in  row: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &row[i]);
                }
                matrix1 = addRow(matrix1, row, size);
                printf("row add in matrix 1.\n");
                break;
            }

            case 2: {
                int row[100];
                int size;
                printf("enter number of element in a row: ");
                scanf("%d", &size);
                printf("ente   elements in  row: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &row[i]);
                }
                matrix2 = addRow(matrix2, row, size);
                printf("row added matrix 2.\n");
                break;
            }

            case 3: {
                printf("matrix 1:\n");
                display(matrix1);
                break;
            }

            case 4: {
                printf("matrix 2:\n");
                display(matrix2);
                break;
            }

            case 5: {
                result = matrixAdd(matrix1, matrix2);
                printf(" addition result:..\n");
                display(result);
                break;
            }

            case 6: {
                result = matrixMul(matrix1, matrix2);
                printf("multiplication result:..\n");
                display(result);
                break;
            }

            case 7: {
                printf("exiting...\n");
                break;
            }

            default: {
                printf("invalid choice.\n");
                break;
            }
        }
        printf("\n");

    } while (choice != 7);

    // Freeing memory (not implemented here)
    return 0;
}
