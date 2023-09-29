#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Function to print the elements of an array
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

// Function to swap two elements
void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

// Function to find the minimum element in an array
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
    return min;
}

// Function to perform selection sort on an array
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

// Function to fill the array with elements
void fill(char **av, int *ptr, int size)
{
    int i;

    i = 2;
    while(av[i] && size--)
	*ptr++ = atoi(av[i++]); 
}

// Unit tests for selection sort algorithm
void test_cases()
{
    int arr1[] = {3, 2, 1, 4};
    int arr2[] = {10, 5, 8, 3};
    int arr3[] = {-1, -5, 0, 7, 2};

    // Test case 1
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    selection_sort(arr1, size1);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 3);
    assert(arr1[3] == 4);

    // Test case 2
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    selection_sort(arr2, size2);
    assert(arr2[0] == 3);
    assert(arr2[1] == 5);
    assert(arr2[2] == 8);
    assert(arr2[3] == 10);

    // Test case 3
    int size3 = sizeof(arr3)/sizeof(arr3[0]);
    selection_sort(arr3, size3);
    assert(arr3[0] == -5);
    assert(arr3[1] == -1);
    assert(arr3[2] == 0);
    assert(arr3[3] == 2);
    assert(arr3[4] == 7);
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
    test_cases();

    return EXIT_SUCCESS;
}