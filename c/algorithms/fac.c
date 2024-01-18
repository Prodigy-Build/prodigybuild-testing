#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (n < 0) {
        printf("Error: input is less than 0\n");
        exit(1);
    }
    return n * factorial(n - 1);
}

int main() {
    for(int i = 1; i <= 5 ; i++){
        printf("factorial(%d): %d\n", i , factorial(i));
    }

    printf("factorial(-1): %d", factorial(-1));
    
    return 1;
}