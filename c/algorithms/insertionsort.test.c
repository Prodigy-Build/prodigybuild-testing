```c
#include <stdio.h>
#include <assert.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int n = sizeof(unsorted) / sizeof(unsorted[0]);
    int sorted[n];
    
    insertionSort(unsorted, n);
    
    // Unit tests
    assert(sorted[0] == 3);
    assert(sorted[1] == 4);
    assert(sorted[2] == 5);
    assert(sorted[3] == 6);
    assert(sorted[4] == 9);
    
    return 0;
}
```