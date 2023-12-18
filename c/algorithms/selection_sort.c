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
    int arr1[4] = {1, 2, 3, 4};
    printf("Expected output: [1,2,3,4], Actual output: ");
    print_arr(arr1, 4);

    int arr2[5] = {0, -1, -2, -3, -4};
    printf("Expected output: [0,-1,-2,-3,-4], Actual output: ");
    print_arr(arr2, 5);

    int arr3[1] = {100};
    printf("Expected output: [100], Actual output: ");
    print_arr(arr3, 1);
}


void test_swap()
{
    int a = 3;
    int b = 5;
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
}

void test_find_min()
{
    int arr1[4] = {1, 2, 3, 4};
    int *min1 = find_min(arr1, 4);
    printf("Expected output: address of element 0x%p, Actual output: address of element 0x%p\n", &arr1[0], min1);

    int arr2[5] = {0, -1, -2, -3, -4};
    int *min2 = find_min(arr2, 5);
    printf("Expected output: address of element 0x%p, Actual output: address of element 0x%p\n", &arr2[4], min2);

    int arr3[1] = {100};
    int *min3 = find_min(arr3, 1);
    printf("Expected output: address of element 0x%p, Actual output: address of element 0x%p\n", &arr3[0], min3);
}

void test_selection_sort()
{
    int arr1[4] = {3, 1, 4, 2};
    selection_sort(arr1, 4);
    printf("Expected output: [1,2,3,4], Actual output: ");
    print_arr(arr1, 4);

    int arr2[6] = {-2, 5, 0, -4, 3, -1};
    selection_sort(arr2, 6);
    printf("Expected output: [-4,-2,-1,0,3,5], Actual output: ");
    print_arr(arr2, 6);

    int arr3[1] = {100};
    selection_sort(arr3, 1);
    printf("Expected output: [100], Actual output: ");
    print_arr(arr3, 1);
}

void test_fill()
{
    char *argv1[] = {"./test", "4", "1", "2", "3"};
    int arr1[4];
    fill(argv1, arr1, 4);
    printf("Expected output: [1,2,3,0], Actual output: ");
    print_arr(arr1, 4);

    char *argv2[] = {"./test", "6", "-2", "5", "0", "-4", "3"};
    int arr2[6];
    fill(argv2, arr2, 6);
    printf("Expected output: [-2,5,0,-4,3,0], Actual output: ");
    print_arr(arr2, 6);

    char *argv3[] = {"./test", "1", "100"};
    int arr3[1];
    fill(argv3, arr3, 1);
    printf("Expected output: [100], Actual output: ");
    print_arr(arr3, 1);
}

int main()
{
    // Call the test functions
    test_print_arr();
    test_swap();
    test_find_min();
    test_selection_sort();
    test_fill();

    return EXIT_SUCCESS;
}