#include <stdio.h>
#include <assert.h>

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

int main() {
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[] = {3, 4, 5, 6, 9};

    int n = sizeof(unsorted) / sizeof(unsorted[0]);

    insertionSort(unsorted, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", unsorted[i]);
    }

    return 0;
}

// Unit Test Cases
void testInsertionSort() {
    // Test case 1
    int arr1[] = {5, 6, 4, 3, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSort(arr1, n1);
    int sorted1[] = {3, 4, 5, 6, 9};
    for (int i = 0; i < n1; i++) {
        assert(arr1[i] == sorted1[i]);
    }

    // Test case 2
    int arr2[] = {};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, n2);
    int sorted2[] = {};
    for (int i = 0; i < n2; i++) {
        assert(arr2[i] == sorted2[i]);
    }
}

// Run test cases
int main() {
    testInsertionSort();
    return 0;
}