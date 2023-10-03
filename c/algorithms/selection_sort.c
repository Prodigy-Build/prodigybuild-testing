#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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
        *ptr++ = atoi(av[i++]); 
}

// Unit Tests
void test_print_arr()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30, 40, 50};
    int arr3[] = {100, 200, 300, 400, 500};

    print_arr(arr1, 5);
    print_arr(arr2, 5);
    print_arr(arr3, 5);
}

void test_swap()
{
    int a = 10;
    int b = 20;
    swap(&a, &b);
    assert(a == 20);
    assert(b == 10);
}

void test_find_min()
{
    int arr[] = {5, 3, 1, 4, 2};
    int *min = find_min(arr, 5);
    assert(*min == 1);

    int arr2[] = {15, 12, 23, 10, 8};
    min = find_min(arr2, 5);
    assert(*min == 8);
}

void test_selection_sort()
{
    int arr[] = {5, 3, 1, 4, 2};
    selection_sort(arr, 5);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    assert(arr[3] == 4);
    assert(arr[4] == 5);

    int arr2[] = {10, 5, 8, 3, 6};
    selection_sort(arr2, 5);
    assert(arr2[0] == 3);
    assert(arr2[1] == 5);
    assert(arr2[2] == 6);
    assert(arr2[3] == 8);
    assert(arr2[4] == 10);
}

void test_fill()
{
    char *av[] = {"./your-executable-name", "5", "1", "2", "3", "4", "5", NULL};
    int arr[5];
    fill(av, arr, 5);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    assert(arr[3] == 4);
    assert(arr[4] == 5);
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