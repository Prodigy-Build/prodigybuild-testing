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

void test_print_arr(void)
{
    int arr[] = {1, 2, 3};
    print_arr(arr, 3);
}

void test_swap(void)
{
    int a = 1;
    int b = 2;
    swap(&a, &b);
    assert(a == 2 && b == 1);
}

void test_find_min(void)
{
    int arr[] = {3, 1, 2};
    int *min = find_min(arr, 3);
    assert(*min == 1);
}

void test_selection_sort(void)
{
    int arr[] = {3, 1, 2};
    selection_sort(arr, 3);
    assert(arr[0] == 1 && arr[1] == 2 && arr[2] == 3);
}

void test_fill(void)
{
    int arr[3];
    char *av[] = {"command", "3", "1", "2"};
    fill(av, arr, 3);
    assert(arr[0] == 1 && arr[1] == 2 && arr[2] == 0);
}

int main(void)
{
    test_print_arr();
    test_swap();
    test_find_min();
    test_selection_sort();
    test_fill();
    return 0;
}