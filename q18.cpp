#include <stdio.h>

int findLargestElement(int mat[][100], int rows, int cols) {
    int largest = mat[0][0];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] > largest) {
                largest = mat[i][j];
            }
        }
    }
    
    return largest;
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int mat[100][100];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int largest = findLargestElement(mat, rows, cols);
    printf("The largest element in the matrix is: %d\n", largest);

    return 0;
}

