#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int *array, int len);
bool array_equals(int *expected, int *actual, int len);

// Unit tests
void test_bubble_sort() {
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(arr1, 10);
    int expected1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    printf("Bubble Sort Test 1: %s\n", array_equals(expected1, arr1, 10) ? "Passed" : "Failed");

    int arr2[] = {5, 3, 8, 2, 1, 6, 10, 7, 4, 9};
    bubble_sort(arr2, 10);
    int expected2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Bubble Sort Test 2: %s\n", array_equals(expected2, arr2, 10) ? "Passed" : "Failed");

    int arr3[] = {2, 4, 6, 8, 10, 9, 7, 5, 3, 1};
    bubble_sort(arr3, 10);
    int expected3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Bubble Sort Test 3: %s\n", array_equals(expected3, arr3, 10) ? "Passed" : "Failed");
}

bool array_equals(int *expected, int *actual, int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (expected[i] != actual[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    test_bubble_sort();
    return 0;
}

void bubble_sort(int *array, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}