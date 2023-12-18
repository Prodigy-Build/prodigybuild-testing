#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int *array, int len) 
{
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

int main(void) 
{
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}

// UNIT TEST CASES

// Test Case 1: Sorting an already sorted array should give the same array
void test_bubble_sort_sorted_array() {
    int arr[] = {1, 2, 3, 4, 5};
    bubble_sort(arr, 5);
    bool isSorted = true;
    for (int i = 0; i < 4; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }
    assert(isSorted);
}

// Test Case 2: Sorting a reverse-sorted array should give a sorted array
void test_bubble_sort_reverse_sorted_array() {
    int arr[] = {5, 4, 3, 2, 1};
    bubble_sort(arr, 5);
    bool isSorted = true;
    for (int i = 0; i < 4; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }
    assert(isSorted);
}

// Test Case 3: Sorting an array with duplicate elements should produce correct result
void test_bubble_sort_duplicate_elements() {
    int arr[] = {5, 2, 3, 2, 1, 4, 4, 1};
    bubble_sort(arr, 8);
    int expected[] = {1, 1, 2, 2, 3, 4, 4, 5};
    bool isEqual = true;
    for (int i = 0; i < 8; i++) {
        if (arr[i] != expected[i]) {
            isEqual = false;
            break;
        }
    }
    assert(isEqual);
}

// Test Case 4: Sorting an empty array should not throw any error
void test_bubble_sort_empty_array() {
    int arr[] = {};
    bubble_sort(arr, 0);
    // No assertion needed as this is not a test for the sorted array
}

// Test Case 5: Sorting a large array should produce correct result
void test_bubble_sort_large_array() {
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = 1000 - i;
    }
    bubble_sort(arr, 1000);
    bool isSorted = true;
    for (int i = 0; i < 999; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }
    assert(isSorted);
}