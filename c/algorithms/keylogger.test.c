#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void insertionSort(int arr[], int n);

int main() {
    // Test case 1
    int arr1[] = {5, 6, 4, 3, 9};
    int sortedArr1[] = {3, 4, 5, 6, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    insertionSort(arr1, n1);
    for (int i = 0; i < n1; i++) {
        assert(arr1[i] == sortedArr1[i]);
    }

    // Test case 2
    int arr2[] = {10, 20, 30, 40, 50};
    int sortedArr2[] = {10, 20, 30, 40, 50};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    insertionSort(arr2, n2);
    for (int i = 0; i < n2; i++) {
        assert(arr2[i] == sortedArr2[i]);
    }

    // Test case 3
    int arr3[] = {50, 40, 30, 20, 10};
    int sortedArr3[] = {10, 20, 30, 40, 50};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    insertionSort(arr3, n3);
    for (int i = 0; i < n3; i++) {
        assert(arr3[i] == sortedArr3[i]);
    }

    printf("All test cases passed.");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}