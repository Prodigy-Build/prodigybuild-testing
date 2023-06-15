

#include <stdio.h>
#include <assert.h>

/* Insertion Sort Test */

void insertion_sort(int *arr, int size);

int main()
{
    int arr[] = {5, 6, 4, 3, 9};
    int size = 5;
    int expected[] = {3, 4, 5, 6, 9};

    insertion_sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        assert(arr[i] == expected[i]);
    }

    printf("Insertion Sort Test Passed!\n");
}

