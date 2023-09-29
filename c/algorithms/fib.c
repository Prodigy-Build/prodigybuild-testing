#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        int a = 1;
        int b = 1;
        int result = 0;
        for (int i = 3; i <= n; i++) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
}

int main() {
    // Unit tests
    printf("%d\n", fibonacci(0));  // Expected output: 0
    printf("%d\n", fibonacci(1));  // Expected output: 1
    printf("%d\n", fibonacci(2));  // Expected output: 1
    printf("%d\n", fibonacci(5));  // Expected output: 5
    printf("%d\n", fibonacci(10)); // Expected output: 55
    
    return 0;
}