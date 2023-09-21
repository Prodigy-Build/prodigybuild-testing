/* Include necessary libraries */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

/* Main Function */
int main()
{
    /* Define size variable */
    int size;
    
    /* Prompt and handle size input from user */
    printf("Size: ");
    scanf("%d", &size);

    /* Allocate memory for the array */
    int *arr = (int*)malloc(size * sizeof(int));
    printf("Array elements: ");

    /* Input array elements from the user */
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Perform quick sort on the array */
    quick_sort(arr, 0, size - 1);

    /* Print the sorted array */
    printf("Sorted array:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    
    printf("\n");

    /* Free up the memory allocated for the array */
    free(arr);

    return 0;
}

/* Function to swap two elements */
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

/* Function to partition the array */
int partition(int a[], int l, int h)
{
    int i = l, j = l, p = h;

    /* Move elements lower than pivot to the left */
    while (i < h)
    {
        if (a[i] < a[p])
        {
            swap(&a[i], &a[j]);
            j++;
        }
        i++;
    }
    
    /* Place pivot at the correct position */
    swap(&a[p], &a[j]);

    /* Return pivot position */
    return j;
}

/* Recursive quick sort function */
void quick_sort(int a[], int l, int h)
{
    int p;

    /* Perform quick sort if there is more than one element in the subarray */
    if (l < h)
    {
        p = partition(a, l, h);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, h);
    }

    return;
}