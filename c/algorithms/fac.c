#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n < 0) {
        printf("Error! Factorial of a negative number doesn't exist.");
        exit(1);
    }
    else if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}


int main() {
    printf("factorial(1): %d\n", factorial(1));
    printf("factorial(2): %d\n", factorial(2));
    printf("factorial(3): %d\n", factorial(3));
    printf("factorial(4): %d\n", factorial(4));
    printf("factorial(5): %d\n", factorial(5));

    printf("factorial(-1): %d\n", factorial(-1));

    return 0;
}