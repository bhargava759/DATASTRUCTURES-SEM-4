#include <stdio.h>

void findElementsRepeatedTwice(int arr[], int size) {
    printf("Elements repeated twice in the array: ");
    
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 2) {
            printf("%d ", arr[i]);
        }
    }
    
    printf("\n");
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

    findElementsRepeatedTwice(arr, size);

    return 0;
}

