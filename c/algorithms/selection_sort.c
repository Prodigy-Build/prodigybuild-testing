#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_arr(int *ptr, int size);

void swap(int *a, int *b);

int *find_min(int *ptr, int size);

void selection_sort(int *ptr, int size);

void fill(char **av, int *ptr, int size);

// Unit tests for selection_sort function
void test_selection_sort()
{
    int arr1[] = {5, 4, 3, 2, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    selection_sort(arr1, size1);
    int expected1[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < size1; i++)
    {
        assert(arr1[i] == expected1[i]);
    }

    int arr2[] = {10, 32, 21, 19, 23, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    selection_sort(arr2, size2);
    int expected2[] = {5, 10, 19, 21, 23, 32};
    for (int i = 0; i < size2; i++)
    {
        assert(arr2[i] == expected2[i]);
    }

    int arr3[] = {99, 88, 77, 66, 55, 44, 33, 22, 11};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    selection_sort(arr3, size3);
    int expected3[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    for (int i = 0; i < size3; i++)
    {
        assert(arr3[i] == expected3[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        puts("Usage: ./your-executable-name [array size] [array]");
        puts("Example: ./your-executable-name 3 2 1 0");
        return EXIT_FAILURE;
    }
    int size = atoi(argv[1]);
    if (!size)
    {
        puts("Error: size of array can't be 0");
        return EXIT_FAILURE;
    }
    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr)
        return EXIT_FAILURE;
    fill(argv, arr, size);

    printf("Before sorting: ");
    print_arr(arr, size);

    selection_sort(arr, size);

    printf("After sorting:  ");
    print_arr(arr, size);

    free(arr);

    // Run unit tests
    test_selection_sort();

    return EXIT_SUCCESS;
}

void print_arr(int *ptr, int size)
{
    putchar('[');
    while (size--)
    {
        printf("%d", *ptr++);
        if (size)
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
    while (size--)
    {
        if (*ptr < *min)
            min = ptr;
        ptr++;
    }
    return (min);
}

void selection_sort(int *ptr, int size)
{
    int *min;

    while (--size)
    {
        if ((min = find_min(ptr + 1, size)))
        {
            if (*ptr > *min)
                swap(ptr, min);
        }
        ptr++;
    }
}

void fill(char **av, int *ptr, int size)
{
    int i;

    i = 2;
    while (av[i] && size--)
        *ptr++ = atoi(av[i++]);
}