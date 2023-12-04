#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

int main()
{
    int size;
    printf("Size: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, size - 1);

    printf("Sorted array:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return (i + 1);
}

void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }

    return;
}