

c/algorithms/countTest.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "count.h"

/* Test count() */
void test_count() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int target = 5;
    int result = count(arr, size, target);
    assert(result == 1);
}

int main() {
    test_count();
    printf("count() tests passed!\n");
    return 0;
}

