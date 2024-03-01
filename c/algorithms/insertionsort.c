#include <stdio.h>
#include <stdbool.h>

void insertionSort(int arr[], int n)
{
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

void test_insertionSort()
{
    // Test case 1
    int arr1[] = {5, 6, 4, 3, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSort(arr1, n1);
    printf("Sorted array: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Test case 2
    int arr2[] = {9, 8, 7, 6, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, n2);
    printf("Sorted array: ");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Test case 3
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr3, n3);
    printf("Sorted array: ");
    for (int i = 0; i < n3; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");
}

int main()
{
    test_insertionSort();
    return 0;
}