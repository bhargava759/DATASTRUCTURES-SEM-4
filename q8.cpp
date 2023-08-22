#include <stdio.h>

int fibonacciSum(int n) {
    if (n <= 0) {
        return 0;
    }

    int fib1 = 0, fib2 = 1;
    int sum = fib1 + fib2;

    for (int i = 2; i <= n; i++) {
        int fibCurrent = fib1 + fib2;
        sum += fibCurrent;
        fib1 = fib2;
        fib2 = fibCurrent;
    }

    return sum;
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int sum = fibonacciSum(n);

    printf("Sum of the first %d Fibonacci numbers: %d\n", n, sum);

    return 0;
}

