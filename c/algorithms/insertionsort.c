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

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5] = {0};

    insertionSort(unsorted, sizeof(unsorted) / sizeof(unsorted[0]));

    assert(unsorted[0] == 3);
    assert(unsorted[1] == 4);
    assert(unsorted[2] == 5);
    assert(unsorted[3] == 6);
    assert(unsorted[4] == 9);

    return 0;
}