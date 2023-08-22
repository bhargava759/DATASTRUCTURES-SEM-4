#include <stdio.h>
int reverse(int x) {
    int reversed = 0;
    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed;
}
int main() {
    int num;
    printf("Enter a 32-bit signed integer: ");
    scanf("%d", &num);   
    int reversed = reverse(num);  
    printf("Reversed integer: %d\n", reversed);
    return 0;
}

