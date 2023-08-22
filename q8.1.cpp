#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int fibonacciSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += fibonacci(i);
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

