#include <stdio.h>
#include <stdbool.h>

void test_bubble_sort_1() {
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int expected[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    int len = sizeof(yarr) / sizeof(yarr[0]);

    bubble_sort(yarr, len);

    bool passed = true;
    for (int i = 0; i < len; i++) {
        if (yarr[i] != expected[i]) {
            passed = false;
            break;
        }
    }

    printf("test_bubble_sort_1: %s\n", passed ? "passed" : "failed");
}

void test_bubble_sort_2() {
    int yarr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(yarr) / sizeof(yarr[0]);

    bubble_sort(yarr, len);

    bool passed = true;
    for (int i = 0; i < len; i++) {
        if (yarr[i] != expected[i]) {
            passed = false;
            break;
        }
    }

    printf("test_bubble_sort_2: %s\n", passed ? "passed" : "failed");
}

int main(void) {
    test_bubble_sort_1();
    test_bubble_sort_2();

    return 0;
}