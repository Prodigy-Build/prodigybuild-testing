


// even_or_odd.c
#include <stdio.h>

int even_or_odd(int num) {
    if (num % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (even_or_odd(num) == 0) {
        printf("The number is even.\n");
    } else {
        printf("The number is odd.\n");
    }
    return 0;
}

// even_or_odd_test.c
#include <stdio.h>
#include <assert.h>

int even_or_odd(int num);

int main() {
    assert(even_or_odd(2) == 0);
    assert(even_or_odd(3) == 1);
    printf("All tests passed!\n");
    return 0;
}