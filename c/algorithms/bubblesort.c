#include <stdio.h>
#include <assert.h>

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

void test_bubble_sort() {
    // Test case 1: Array is already sorted
    int arr1[] = {1, 2, 3, 4, 5};
    bubble_sort(arr1, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr1[i] == i + 1);
    }

    // Test case 2: Array is reverse sorted
    int arr2[] = {5, 4, 3, 2, 1};
    bubble_sort(arr2, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr2[i] == i + 1);
    }

    // Test case 3: Array contains duplicate elements
    int arr3[] = {3, 7, 2, 4, 5, 4, 1};
    bubble_sort(arr3, 7);
    for (int i = 0; i < 7; i++) {
        assert(arr3[i] == i + 1);
    }

    // Test case 4: Array is empty
    int arr4[] = {};
    bubble_sort(arr4, 0);
    assert(sizeof(arr4) == 0);

    // Test case 5: Array has only one element
    int arr5[] = {10};
    bubble_sort(arr5, 1);
    assert(arr5[0] == 10);
}

int main(void) {
    test_bubble_sort();

    return 0;
}