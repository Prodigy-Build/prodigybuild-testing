#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

void tests()
{
    // Test swap function
    int a = 5, b = 10;
    swap(&a, &b);
    printf("Swapped values: a = %d, b = %d\n", a, b);

    // Test partition function
    int arr1[] = {4, 1, 8, 2, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int pivotIndex = partition(arr1, 0, n - 1);
    printf("Pivot index: %d\n", pivotIndex);
    printf("Partitioned array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr1[i]);
    }
    printf("\n");

    // Test quick_sort function
    int arr2[] = {4, 1, 8, 2, 9};
    n = sizeof(arr2) / sizeof(arr2[0]);
    quick_sort(arr2, 0, n - 1);
    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr2[i]);
    }
    printf("\n");
}

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

    tests(); // Run unit tests

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

int partition(int a[], int l, int h)
{
    int i = l, j = l, p = h;

    while (i < h)
    {
        if (a[i] < a[p])
        {
            swap(&a[i], &a[j]);
            j++;
        }
        i++;
    }

    swap(&a[p], &a[j]);

    return j;
}

void quick_sort(int a[], int l, int h)
{
    int p;

    if (l < h)
    {
        p = partition(a, l, h);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, h);
    }

    return;
}