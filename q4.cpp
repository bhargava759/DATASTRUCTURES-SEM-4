#include <stdio.h>

int searchRegNo(int regNos[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (regNos[i] == target) {
            return i; // Return the index where the reg no is found
        }
    }
    return -1; // Return -1 if reg no is not found
}

int main() {
    int size;

    printf("Enter the number of registration numbers: ");
    scanf("%d", &size);

    int regNos[size];

    printf("Enter the registration numbers:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &regNos[i]);
    }

    int targetRegNo;
    printf("Enter the registration number to search: ");
    scanf("%d", &targetRegNo);

    int foundIndex = searchRegNo(regNos, size, targetRegNo);
    if (foundIndex != -1) {
        printf("Registration number %d found at index %d.\n", targetRegNo, foundIndex);
    } else {
        printf("Registration number %d not found.\n", targetRegNo);
    }

    return 0;
}

