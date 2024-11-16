#include <stdio.h>
#include <stdlib.h>

// Structure to represent a non-zero element in the sparse matrix
struct Element {
    int row;
    int col;
    int value;
};

// Node structure for the sparse matrix
struct Node {


    struct Element data;
    struct Node* right; // Link to the next non-zero element in the row
    struct Node* down;  // Link to the next non-zero element in the column
};

// Function to create a new node with an element
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data.row = row;
    newNode->data.col = col;
    newNode->data.value = value;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

// Function to create a multilinked sparse matrix
struct Node* createSparseMatrix(int rows, int cols) {
    int i, j, value;
    struct Node* matrix[rows][cols];

    // Input data for each non-zero element and create nodes
    printf("Enter sparse matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &value);

            // Create a node only for non-zero elements
            if (value != 0) {
                matrix[i][j] = createNode(i + 1, j + 1, value);
            } else {
                matrix[i][j] = NULL;
            }
        }
    }

    // Link the nodes to create the multilinked structure
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != NULL) {
                if (j < cols - 1) {
                    matrix[i][j]->right = matrix[i][j + 1];
                }
                if (i < rows - 1) {
                    matrix[i][j]->down = matrix[i + 1][j];
                }
            }
        }
    }

    // Return the top-left node of the matrix
    return matrix[0][0];
}

// Function to display the sparse matrix
void displaySparseMatrix(struct Node* start, int rows, int cols) {
    int i, j;
    struct Node* currentRow = start;

    // Traverse rows
    for (i = 1; i <= rows; i++) {
        struct Node* currentCol = currentRow;

        // Traverse columns in the current row
        for (j = 1; j <= cols; j++)
         {
            if (currentCol != NULL && currentCol->data.row == i && currentCol->data.col == j) 
            {
                printf("%d\t", currentCol->data.value);
                currentCol = currentCol->right;
            } else {
                printf("0\t");
            }
        }

        printf("\n");
        currentRow = currentRow->down; // Move to the next row
    }
}

int main() {
    int rows, cols, choice;
    struct Node* sparseMatrix = NULL;

    printf("Enter the number of rows in the sparse matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the sparse matrix: ");
    scanf("%d", &cols);

    do {
        printf("\nMenu:\n");
        printf("1. Create Sparse Matrix\n");
        printf("2. Display Sparse Matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sparseMatrix = createSparseMatrix(rows, cols);
                printf("Sparse matrix created successfully!\n");
                break;
            case 2:
                if (sparseMatrix != NULL) {
                    printf("Sparse Matrix:\n");
                    displaySparseMatrix(sparseMatrix, rows, cols);
                } else {
                    printf("Sparse matrix is not created yet. Please choose option 1 to create a sparse matrix.\n");
                }
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
