#include <stdio.h>

void printFrequentCounts(int arr[], int size) {
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > 1 && count >= maxCount) {
            maxCount = count;
            printf("Number %d is repeated %d times.\n", arr[i], count);
        }
    }
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

    printf("Frequently repeated numbers and their counts:\n");
    printFrequentCounts(arr, size);

    return 0;
}

