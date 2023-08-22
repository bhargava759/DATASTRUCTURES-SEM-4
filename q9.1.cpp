#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        unsigned long long result = factorial(n);
        printf("Factorial of %d is %llu\n", n, result);
    }

    return 0;
}

