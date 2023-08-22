#include <stdio.h>

int findElementLocation(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the element is found
        }
    }
    return -1; // Return -1 if element is not found
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

    int targetElement;
    printf("Enter the element to search: ");
    scanf("%d", &targetElement);

    int location = findElementLocation(arr, size, targetElement);
    if (location != -1) {
        printf("Element %d found at index %d.\n", targetElement, location);
    } else {
        printf("Element %d not found in the array.\n", targetElement);
    }

    return 0;
}

