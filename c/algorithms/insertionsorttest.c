#include <stdio.h>
#include <stdbool.h> // for boolean data type

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

/* Function to print an array */
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Unit test cases for insertionSort

int main()
{
    // Test Case 1
    int arr1[] = {5, 6, 4, 3, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSort(arr1, n1);
    printf("Sorted array in test case 1 : \n");
    printArray(arr1, n1);

    // Test Case 2
    int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, n2);
    printf("Sorted array in test case 2 : \n");
    printArray(arr2, n2);

    // Test Case 3
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr3, n3);
    printf("Sorted array in test case 3 : \n");
    printArray(arr3, n3);

    return 0;
}