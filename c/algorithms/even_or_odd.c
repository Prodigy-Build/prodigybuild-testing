#include <stdio.h>
#include <stdbool.h>

bool is_even(long num) {
    return num % 2 == 0;
}

int main() {
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);

    if (is_even(num)) {
        printf("Even");
    } else {
        printf("Odd");
    }
    return 0;
}