#include <stdio.h>
#define SIZE 5

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

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
    int unsorted[SIZE] = {5, 6, 4, 3, 9};
    int sorted[SIZE];

    int i;
    for (i = 0; i < SIZE; i++) sorted[i] = unsorted[i];

    insertionSort(sorted, SIZE);

    for (i = 0; i < SIZE; i++) printf("%d ", sorted[i]);

    return 0;
}