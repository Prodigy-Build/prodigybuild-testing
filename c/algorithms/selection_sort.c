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


// Unit test cases for the selection sort function

void test_selection_sort()
{
    // Test case 1: Array with positive integers
    int arr1[] = {4, 2, 5, 3, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    selection_sort(arr1, size1);
    assert(arr1[0] == 1 && arr1[1] == 2 && arr1[2] == 3 && arr1[3] == 4 && arr1[4] == 5);

    // Test case 2: Array with negative integers
    int arr2[] = {-4, -2, -5, -3, -1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    selection_sort(arr2, size2);
    assert(arr2[0] == -5 && arr2[1] == -4 && arr2[2] == -3 && arr2[3] == -2 && arr2[4] == -1);

    // Test case 3: Array with duplicate elements
    int arr3[] = {1, 2, 3, 4, 2};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    selection_sort(arr3, size3);
    assert(arr3[0] == 1 && arr3[1] == 2 && arr3[2] == 2 && arr3[3] == 3 && arr3[4] == 4);

    // Test case 4: Empty array
    int arr4[] = {};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    selection_sort(arr4, size4);  // No effect
    assert(size4 == 0);

    // Test case 5: Array with a single element
    int arr5[] = {42};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    selection_sort(arr5, size5);  // No effect
    assert(size5 == 1 && arr5[0] == 42);
}

int main()
{
    test_selection_sort();
    return 0;
}