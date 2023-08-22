#include <stdio.h>

void findMissingElement(int arr[], int size) {
    int totalSum = 0;
    for (int i = 0; i < size; i++) {
        totalSum += arr[i];
    }

    int expectedSum = (size + 1) * (size + 2) / 2;

    int missingElement = expectedSum - totalSum;

    printf("Missing element in the array: %d\n", missingElement);
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    findMissingElement(arr, size);

    return 0;
}

