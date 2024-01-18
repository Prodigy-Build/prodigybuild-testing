#include <stdio.h>
#include <stdlib.h>

void print_arr(int *ptr, int size)
{
    printf("[");
    for (int i = 0; i < size; ++i)
    {
	printf("%d", ptr[i]);
	if(i != size - 1)
	    printf(",");
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
    int *min_ptr = ptr;
    for (int i = 0; i < size; ++i)
    {
	if(ptr[i] < *min_ptr)
	    min_ptr = ptr+i;
    }
    return min_ptr;
}

void selection_sort(int *ptr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
	int *min_ptr = find_min(ptr + i + 1, size - i - 1);
	if(ptr[i] > *min_ptr)
	    swap(ptr + i, min_ptr);
    }
}

void fill(char **av, int *ptr, int size)
{
    for (int i = 0; i < size; ++i)
	ptr[i] = atoi(av[i+2]); 
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
	printf("Usage: ./your-executable-name [array size] [array]\n");
	printf("Example: ./your-executable-name 3 2 1 0\n");
	return EXIT_FAILURE;
    }
    int size = atoi(argv[1]);
    if(!size)
    {
	printf("Error: size of array can't be 0\n");
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