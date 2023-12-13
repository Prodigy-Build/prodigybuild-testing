#include <stdio.h>
#include <stdbool.h>

void insertionSort(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Define unit test cases here
void testInsertionSort()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int n = sizeof(unsorted) / sizeof(unsorted[0]);
    int expectedOutput[] = {3, 4, 5, 6, 9};

    insertionSort(unsorted, n);

    bool pass = true;
    for (int i = 0; i < n; i++)
    {
        if (unsorted[i] != expectedOutput[i])
        {
            pass = false;
            break;
        }
    }

    if (pass)
    {
        printf("Insertion sort test case passed\n");
    }
    else
    {
        printf("Insertion sort test case failed\n");
    }
}

int main()
{
    testInsertionSort();

    return 0;
}