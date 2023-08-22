#include <stdio.h>

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int fifthIteratedElement = -1; // Default value

    for (int i = 0; i < size; i++) {
        if (i == 4) { // The fifth iterated element (assuming 0-based indexing)
            fifthIteratedElement = arr[i];
            break;
        }
    }

    if (fifthIteratedElement != -1) {
        printf("The fifth iterated element: %d\n", fifthIteratedElement);
    } else {
        printf("There is no fifth iterated element.\n");
    }

    return 0;
}

