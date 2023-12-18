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
    return min;
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

void fill(int *ptr, int size)
{
    int i = 2;
    while(size--)
        *ptr++ = i++; 
}

bool test_selection_sort()
{
    int arr1[] = {3, 2, 1, 4};
    int arr1_expected[] = {1, 2, 3, 4};
    selection_sort(arr1, 4);
    for (int i = 0; i < 4; i++)
    {
        if (arr1[i] != arr1_expected[i])
            return false;
    }

    int arr2[] = {1, 5, 0, -1};
    int arr2_expected[] = {-1, 0, 1, 5};
    selection_sort(arr2, 4);
    for (int i = 0; i < 4; i++)
    {
        if (arr2[i] != arr2_expected[i])
            return false;
    }

    int arr3[] = {};
    int arr3_expected[] = {};
    selection_sort(arr3, 0);
    for (int i = 0; i < 0; i++)
    {
        if (arr3[i] != arr3_expected[i])
            return false;
    }
	
    return true;
}

int main()
{
    if (!test_selection_sort())
    {
        printf("Selection Sort test failed\n");
        return EXIT_FAILURE;
    }

    int size = 4;
    int *arr = (int *)malloc(size * sizeof(int));
    if(!arr)
        return EXIT_FAILURE;

    fill(arr, size);

    printf("Before sorting: ");
    print_arr(arr, size);

    selection_sort(arr, size);

    printf("After sorting:  ");
    print_arr(arr, size);

    free(arr);
    return EXIT_SUCCESS;
}