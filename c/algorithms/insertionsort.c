#include <stdio.h>
#include <stdbool.h>

void insertionSort(int arr[], int n)
{
    int i, j, key;
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

// Unit Test Case
void test_insertionSort()
{
    int arr[] = {5, 6, 4, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    int expected[] = {3, 4, 5, 6, 9};
    bool pass = true;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != expected[i])
        {
            pass = false;
            break;
        }
    }

    if (pass)
    {
        printf("insertionSort test passed.\n");
    }
    else
    {
        printf("insertionSort test failed.\n");
    }
}

int main()
{
    test_insertionSort();
    return 0;
}