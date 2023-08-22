#include <stdio.h>

void concatenateArrays(int arr1[], int size1, int arr2[], int size2, int result[], int *resultSize) {
    int i, j;

    for (i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    for (j = 0; j < size2; j++) {
        result[i + j] = arr2[j];
    }

    *resultSize = size1 + size2;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    int arr1[size1];

    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    int arr2[size2];

    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int resultSize = size1 + size2;
    int result[resultSize];

    concatenateArrays(arr1, size1, arr2, size2, result, &resultSize);

    printf("Concatenated array: ");
    printArray(result, resultSize);

    return 0;
}

