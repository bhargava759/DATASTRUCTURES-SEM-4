#include <stdio.h>
#include <string.h>

void printIndicesOfRepeatedCharacters(char str[]) {
    int length = strlen(str);

    for (int i = 0; i < length - 1; i++) {
        if (str[i] == '\0') {
            continue; // Character has already been marked as repeated
        }

        for (int j = i + 1; j < length; j++) {
            if (str[i] == str[j]) {
                printf("Character '%c' is repeated at indices %d and %d\n", str[i], i, j);
                str[j] = '\0'; // Mark as repeated to avoid duplicate output
            }
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printIndicesOfRepeatedCharacters(str);

    return 0;
}

