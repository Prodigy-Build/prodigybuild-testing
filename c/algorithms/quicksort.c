#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    int arraySize;
    printf("Enter array size: ");
    scanf("%d", &arraySize);

    int *array = malloc(arraySize * sizeof(int));
    printf("Enter array elements: ");
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, arraySize - 1);

    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }

    return;
}