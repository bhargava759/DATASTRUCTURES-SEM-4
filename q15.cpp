#include <stdio.h>

void calculateRowSum(int mat[][100], int rows, int cols, int rowSum[]) {
    for (int i = 0; i < rows; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < cols; j++) {
            rowSum[i] += mat[i][j];
        }
    }
}

void calculateColumnSum(int mat[][100], int rows, int cols, int colSum[]) {
    for (int j = 0; j < cols; j++) {
        colSum[j] = 0;
        for (int i = 0; i < rows; i++) {
            colSum[j] += mat[i][j];
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    int rowSum[100];
    int colSum[100];

    calculateRowSum(mat, rows, cols, rowSum);
    calculateColumnSum(mat, rows, cols, colSum);

    printf("Sum of each row:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i + 1);
        printArray(&rowSum[i], 1);
    }

    printf("Sum of each column:\n");
    for (int j = 0; j < cols; j++) {
        printf("Column %d: ", j + 1);
        printArray(&colSum[j], 1);
    }

    return 0;
}

