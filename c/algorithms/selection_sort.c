#include <stdio.h>
#include <stdlib.h>

void print_arr(int *ptr, int size)
{
    putchar('[');
    for(int i = 0; i < size; i++)
    {
        printf("%d", ptr[i]);
        if(i != size - 1)
            putchar(',');
    }
    printf("]\n");
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int *find_min(int *ptr, int size)
{
    int *min = ptr;
    for(int i = 1; i < size; i++)
    {
        if(ptr[i] < *min)
            min = &ptr[i];
    }
    return min;
}

void selection_sort(int *ptr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int *min = find_min(ptr + i, size - i);
        if(ptr[i] > *min)
            swap(&ptr[i], min);
    }
}

void fill(char **av, int *ptr, int size)
{
    for(int i = 2; i < size + 2; i++)
    {
        ptr[i - 2] = atoi(av[i]);
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
    return EXIT_SUCCESS;
}