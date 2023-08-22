#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index where the target is found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Return -1 if target is not found
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int linearIndex = linearSearch(arr, size, target);
    if (linearIndex != -1) {
        printf("Linear Search: Element %d found at index %d.\n", target, linearIndex);
    } else {
        printf("Linear Search: Element %d not found.\n", target);
    }

    int binaryIndex = binarySearch(arr, size, target);
    if (binaryIndex != -1) {
        printf("Binary Search: Element %d found at index %d.\n", target, binaryIndex);
    } else {
        printf("Binary Search: Element %d not found.\n", target);
    }

    return 0;
}

