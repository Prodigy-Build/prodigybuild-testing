#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = current;
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

int main() {
    int unsorted[] = {5, 6, 4, 3, 9};
    int size = sizeof(unsorted) / sizeof(unsorted[0]);
    
    insertionSort(unsorted, size);

    printArray(unsorted, size);
    
    return 0;
}

// Test Cases

void testInsertionSort() {
    // Test Case 1
    int arr1[] = {5, 6, 4, 3, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSort(arr1, size1);
    int expected1[] = {3, 4, 5, 6, 9};
    for (int i = 0; i < size1; i++) {
        if (arr1[i] != expected1[i]) {
            printf("Test Case 1 Failed\n");
            return;
        }
    }
    
    // Test Case 2
    int arr2[] = {1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, size2);
    int expected2[] = {1};
    for (int i = 0; i < size2; i++) {
        if (arr2[i] != expected2[i]) {
            printf("Test Case 2 Failed\n");
            return;
        }
    }
    
    // Test Case 3
    int arr3[] = {9, 8, 7, 6, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr3, size3);
    int expected3[] = {5, 6, 7, 8, 9};
    for (int i = 0; i < size3; i++) {
        if (arr3[i] != expected3[i]) {
            printf("Test Case 3 Failed\n");
            return;
        }
    }
    
    // All test cases passed
    printf("All Test Cases Passed\n");
}

int main() {
    testInsertionSort();
    return 0;
}