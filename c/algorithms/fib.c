#include <stdio.h>
#include <stdbool.h>

bool isFibonacci(int n) {
    int a = 0, b = 1;

    while (b < n) {
        int temp = a;
        a = b;
        b = temp + b;
    }

    return b == n;
}

int main() {
    // Unit tests for isFibonacci function
    printf("%d\n", isFibonacci(0));  // Expected output: 1 (true)
    printf("%d\n", isFibonacci(1));  // Expected output: 1 (true)
    printf("%d\n", isFibonacci(2));  // Expected output: 1 (true)
    printf("%d\n", isFibonacci(3));  // Expected output: 1 (true)
    printf("%d\n", isFibonacci(4));  // Expected output: 0 (false)
    printf("%d\n", isFibonacci(5));  // Expected output: 1 (true)
    printf("%d\n", isFibonacci(6));  // Expected output: 0 (false)
    printf("%d\n", isFibonacci(7));  // Expected output: 0 (false)
    printf("%d\n", isFibonacci(8));  // Expected output: 1 (true)
    printf("%d\n", isFibonacci(9));  // Expected output: 0 (false)

    return 0;
}