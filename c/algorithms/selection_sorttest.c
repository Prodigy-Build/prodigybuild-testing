```c/algorithms/selection_sort.c```

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_arr(int *ptr, int size)
{
    putchar('[');
    while(size--)
    {
        printf("%d", *ptr++);
        if(size)
            putchar(',');
    }
    printf("]\n");
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int *find_min(int *ptr, int size)
{
    int *min;
    min = ptr;
    while(size--)
    {
        if(*ptr < *min)
            min = ptr;
        ptr++;
    }
    return (min);
}

void selection_sort(int *ptr, int size)
{
    int *min;

    while(--size)
    {
        if((min = find_min(ptr + 1, size)))
        {
            if(*ptr > *min)
                swap(ptr, min);
        }
        ptr++;
    }
}

void fill(char **av, int *ptr, int size)
{
    int i;
    i = 2;
    while(av[i] && size--)
    {
        *ptr++ = atoi(av[i++]);
    }
}

void test_print_arr()
{
    // Test case 1: Empty array
    int arr1[] = {};
    print_arr(arr1, 0);

    // Test case 2: Single element array
    int arr2[] = {5};
    print_arr(arr2, 1);

    // Test case 3: Multiple element array
    int arr3[] = {1, 2, 3, 4, 5};
    print_arr(arr3, 5);
}

void test_swap()
{
    // Test case 1: Swapping two different elements
    int a1 = 1;
    int b1 = 2;
    swap(&a1, &b1);

    // Test case 2: Swapping the same element
    int a2 = 3;
    swap(&a2, &a2);
}

void test_find_min()
{
    // Test case 1: Finding minimum in empty array
    int arr1[] = {};
    int *min1 = find_min(arr1, 0);

    // Test case 2: Finding minimum in array with single element
    int arr2[] = {5};
    int *min2 = find_min(arr2, 1);

    // Test case 3: Finding minimum in array with multiple elements
    int arr3[] = {1, 2, 3, 4, 5};
    int *min3 = find_min(arr3, 5);
}

void test_selection_sort()
{
    // Test case 1: Sorting empty array
    int arr1[] = {};
    selection_sort(arr1, 0);

    // Test case 2: Sorting array with single element
    int arr2[] = {5};
    selection_sort(arr2, 1);

    // Test case 3: Sorting array with multiple elements
    int arr3[] = {3, 1, 4, 2, 5};
    selection_sort(arr3, 5);
}

void test_fill()
{
    // Test case 1: Filling empty array
    char *argv1[] = {"./executable_name", "0"};
    int arr1[0];
    fill(argv1, arr1, 0);

    // Test case 2: Filling array with single element
    char *argv2[] = {"./executable_name", "1", "5"};
    int arr2[1];
    fill(argv2, arr2, 1);

    // Test case 3: Filling array with multiple elements
    char *argv3[] = {"./executable_name", "5", "4", "3", "2", "1"};
    int arr3[5];
    fill(argv3, arr3, 5);
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        puts("Usage: ./your-executable-name [array size] [array]");
        puts("Example: ./your-executable-name 3 2 1 0");
        return EXIT_FAILURE;
    }
    int size = atoi(argv[1]);
    if(!size)
    {
        puts("Error: size of array can't be 0");
        return EXIT_FAILURE;
    }
    int *arr = (int *)malloc(size * sizeof(int));
    if(!arr)
        return EXIT_FAILURE;
    fill(argv, arr, size);

    printf("Before sorting: ");
    print_arr(arr, size);

    selection_sort(arr, size);

    printf("After sorting:  ");
    print_arr(arr, size);

    free(arr);
    return EXIT_SUCCESS;
}
```
