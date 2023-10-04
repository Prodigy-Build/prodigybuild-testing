```c/algorithms/selection_sort.c``` code with unit test cases:

```c
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

void test_print_arr() {
    int arr[5] = {1, 2, 3, 4, 5};
    print_arr(arr, 5);
}

void test_swap() {
    int a = 2, b = 3;
    swap(&a, &b);
    assert(a == 3);
    assert(b == 2);
}

void test_find_min() {
    int arr[5] = {5, 1, 3, 4, 2};
    int *min_ptr = find_min(arr, 5);
    assert(*min_ptr == 1);
}

void test_selection_sort() {
    int arr[5] = {5, 1, 3, 4, 2};
    selection_sort(arr, 5);
    for(int i=0; i<5; i++) {
        assert(arr[i] == i+1);
    }
}

void test_fill() {
    char *av[6] = {"./your-executable-name", "5", "2", "4", "1", "3"};
    int arr[5] = {0};
    fill(av, arr, 5);
    for(int i=0; i<5; i++) {
        assert(arr[i] == i+1);
    }
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

    test_print_arr();
    test_swap();
    test_find_min();
    test_selection_sort();
    test_fill();

    return EXIT_SUCCESS;
}
```