#include <stdio.h>

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
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
    int unsorted[] = {5, 6, 4, 3, 9};
    int size = sizeof(unsorted) / sizeof(unsorted[0]);
    
    insertionSort(unsorted, size);
    
    for (int i = 0; i < size; i++)
    {
        printf("%d ", unsorted[i]);
    }
    
    return 0;
}