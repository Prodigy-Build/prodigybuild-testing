#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n < 0) {
        printf("Input must be a non-negative integer.\n");
        exit(EXIT_FAILURE);
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    for(int i = 1; i <= 5; i++) {
        printf("factorial(%d): %d\n", i, factorial(i));
    }

    printf("factorial(-1): %d\n", factorial(-1));

    return EXIT_SUCCESS;
}