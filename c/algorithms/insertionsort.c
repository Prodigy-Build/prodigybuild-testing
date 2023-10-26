#include <stdio.h>
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

void test_insertionSort()
{
    int arr1[] = {5, 6, 4, 3, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSort(arr1, n1);
    assert(arr1[0] == 3);
    assert(arr1[1] == 4);
    assert(arr1[2] == 5);
    assert(arr1[3] == 6);
    assert(arr1[4] == 9);

    int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, n2);
    assert(arr2[0] == 1);
    assert(arr2[1] == 2);
    assert(arr2[2] == 3);
    assert(arr2[3] == 4);
    assert(arr2[4] == 5);
    assert(arr2[5] == 6);
    assert(arr2[6] == 7);
    assert(arr2[7] == 8);
    assert(arr2[8] == 9);
}

int main()
{
    test_insertionSort();
    return 0;
}