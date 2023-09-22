/* Include necessary libraries */
#include <stdio.h>
#include <stdlib.h>

/* Declare functions */
void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

/* Main function */
int main()
{
    /* Declare an integer for size */
    int size;
    
    /* Prompt user for size */
    printf("Size: ");
    scanf("%d", &size);

    /* Allocate memory for the array */
    int *arr = malloc(size * sizeof(int));

    /* Prompt user for array elements */
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Apply quick sort */
    quick_sort(arr, 0, size - 1);

    /* Print out sorted array */
    printf("Sorted array:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    /* Print a new line */
    printf("\n");

    /* Free allocated memory */
    free(arr);

    return 0;
}

/* Swap function */
void swap(int *a, int *b)
{
    /* Declare a temporary integer */
    int tmp;

    /* Perform the swap */
    tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}

/* Partition function */
int partition(int a[], int l, int h)
{
    /* Declare variables */
    int i = l, j = l, p = h;

    /* Partition array */
    while (i < h)
    {
        if (a[i] < a[p])
        {
            swap(&a[i], &a[j]);
            j++;
        }
        i++;
    }

    /* Final swap */
    swap(&a[p], &a[j]);

    return j;
}

/* Quick sort function */
void quick_sort(int a[], int l, int h)
{
    /* Declare pivot */
    int p;

    /* Continue as long as lower is less than higher */
    if (l < h)
    {
        p = partition(a, l, h);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, h);
    }

    return;
}