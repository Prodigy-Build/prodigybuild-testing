#include <stdio.h>
#include <stdlib.h>
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

void test_print_arr()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Expected: [1,2,3,4,5]\n");
    printf("Actual: ");
    print_arr(arr, size);
}

void test_swap()
{
    int a = 5;
    int b = 10;

    swap(&a, &b);

    assert(a == 10);
    assert(b == 5);
}

void test_find_min()
{
    int arr[] = {5, 2, 8, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *min = find_min(arr, size);

    assert(*min == 1);
}

void test_selection_sort()
{
    int arr[] = {5, 2, 8, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, size);

    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 4);
    assert(arr[3] == 5);
    assert(arr[4] == 8);
}

void test_fill()
{
    char *argv[] = {"./your-executable-name", "5", "1", "2", "3", "4", "5"};
    int size = atoi(argv[1]);
    int *arr = (int *)malloc(size * sizeof(int));

    fill(argv, arr, size);

    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    assert(arr[3] == 4);
    assert(arr[4] == 5);

    free(arr);
}

int main()
{
    test_print_arr();
    test_swap();
    test_find_min();
    test_selection_sort();
    test_fill();

    printf("All tests passed!\n");

    return 0;
}