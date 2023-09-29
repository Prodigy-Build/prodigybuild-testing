#include <stdio.h>
#include <stdlib.h>

int fak(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (n < 0) {
        return 1;
        exit(1);
    }
    return n * fak(n-1);
}

int test_fak() {
    if (fak(1) != 1)
        return 0;
    if (fak(2) != 2)
        return 0;
    if (fak(3) != 6)
        return 0;
    if (fak(4) != 24)
        return 0;
    if (fak(5) != 120)
        return 0;
    if (fak(-1) != 1)
        return 0;
    return 1;
}

int main() {
    printf("fak(1): %d\n", fak(1));
    printf("fak(2): %d\n", fak(2));
    printf("fak(3): %d\n", fak(3));
    printf("fak(4): %d\n", fak(4));
    printf("fak(5): %d\n", fak(5));
    printf("fak(-1): %d\n", fak(-1));

    if (test_fak())
        printf("All test cases pass\n");
    else
        printf("Test cases failed\n");

    return 1;
}