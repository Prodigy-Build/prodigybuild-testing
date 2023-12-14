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
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, size); // Expected output: [1, 2, 3]
}

void test_swap()
{
    int a = 3;
    int b = 5;
    swap(&a, &b);
    assert(a == 5 && b == 3);
}

void test_find_min()
{
    int arr[] = {8, 2, 5, 4, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *min = find_min(arr, size);
    assert(*min == 2);
}

void test_selection_sort()
{
    int arr[] = {8, 2, 5, 4, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);
    assert(arr[0] == 2 && arr[1] == 4 && arr[2] == 5 && arr[3] == 8 && arr[4] == 10);
}

void test_fill()
{
    char *av[] = {"./executable", "5", "8", "2", "5", "4", "10"};
    int size = atoi(av[1]);
    int *arr = (int *)malloc(size * sizeof(int));
    fill(av, arr, size);
    assert(arr[0] == 8 && arr[1] == 2 && arr[2] == 5 && arr[3] == 4 && arr[4] == 10);
    free(arr);
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

    // Run unit tests
    test_print_arr();
    test_swap();
    test_find_min();
    test_selection_sort();
    test_fill();

    return EXIT_SUCCESS;
}