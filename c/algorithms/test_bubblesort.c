.

// test_bubblesort.c
#include <stdio.h>
#include "algorithms/bubblesort.c"

int main() {
    int arr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int expected[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    int len = 10;

    bubble_sort(arr, len);

    for (int i = 0; i < len; i++) {
        if (arr[i] != expected[i]) {
            printf("Test failed!\n");
            return 1;
        }
    }

    printf("Test passed!\n");
    return 0;
}