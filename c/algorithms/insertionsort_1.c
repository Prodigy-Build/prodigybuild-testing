

#include <stdio.h>
#include <assert.h>

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Unit test cases
void test_insertionSort()
{
    int arr[] = {5, 6, 4, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    assert(arr[0] == 3);
    assert(arr[1] == 4);
    assert(arr[2] == 5);
    assert(arr[3] == 6);
    assert(arr[4] == 9);
}

int main()
{
    test_insertionSort();
    printf("All tests passed!\n");
    return 0;
}