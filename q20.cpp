#include <stdio.h>
#include <string.h>

void sortStringAlphabetically(char str[]) {
    int length = strlen(str);
    char temp;

    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    sortStringAlphabetically(str);

    printf("String sorted in alphabetical order: %s\n", str);

    return 0;
}

