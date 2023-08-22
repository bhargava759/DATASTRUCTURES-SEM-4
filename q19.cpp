#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isValidString(const char *str) {
    while (*str) {
        if (!isalpha(*str)) {
            return false; // Non-alphabetic character found
        }
        str++;
    }
    return true; // All characters are alphabetic
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isValidString(str)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}

