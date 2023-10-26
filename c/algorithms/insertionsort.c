```c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void testInsertionSort()
{
    int arr[] = {5, 6, 4, 3, 9};
    int sorted[] = {3, 4, 5, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        assert(arr[i] == sorted[i]);
    }
}

int main()
{
    testInsertionSort();
    
    return 0;
}
```