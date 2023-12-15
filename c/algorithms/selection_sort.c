#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void print_arr(int *ptr, int size)
{
    if (size == 0) {
        printf("[]\n");
        return;
    }

    printf("[%d", ptr[0]);
    for (int i = 1; i < size; i++) {
        printf(", %d", ptr[i]);
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

    for (int i = 1; i < size; i++) {
        if (ptr[i] < *min) {
            min = &ptr[i];
        }
    }

    return min;
}

void selection_sort(int *ptr, int size)
{
    while (size > 1) {
        int *min = find_min(ptr, size);
        if (*min < *ptr) {
            swap(min, ptr);
        }
        ptr++;
        size--;
    }
}

void fill(int *ptr, int size, char **av)
{
    for (int i = 2; i < size + 2; i++) {
        ptr[i - 2] = atoi(av[i]);
    }
}

void test_print_arr()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Expected output: [1, 2, 3, 4, 5]\n");
    printf("Actual output: ");
    print_arr(arr, size);

    int empty_arr[] = {};
    int empty_size = sizeof(empty_arr) / sizeof(empty_arr[0]);

    printf("Expected output: []\n");
    printf("Actual output: ");
    print_arr(empty_arr, empty_size);
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
    int arr[] = {5, 2, 7, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *min = find_min(arr, size);
    printf("Minimum element: %d\n", *min);
}

void test_selection_sort()
{
    int arr[] = {5, 2, 7, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    print_arr(arr, size);

    selection_sort(arr, size);

    printf("After sorting:  ");
    print_arr(arr, size);
}

void test_fill()
{
    int arr[5] = {0};
    int size = sizeof(arr) / sizeof(arr[0]);
    char *av[] = {"./your-executable-name", "5", "1", "2", "3"};

    fill(arr, size, av);

    int expected_arr[] = {1, 2, 3, 0, 0};

    for (int i = 0; i < size; i++) {
        assert(arr[i] == expected_arr[i]);
    }

    printf("Array filled successfully\n");
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        puts("Usage: ./your-executable-name [array size] [array]");
        puts("Example: ./your-executable-name 3 2 1 0");
        return EXIT_FAILURE;
    }

    int size = atoi(argv[1]);
    if (!size) {
        puts("Error: size of array can't be 0");
        return EXIT_FAILURE;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) {
        return EXIT_FAILURE;
    }
    memset(arr, 0, size * sizeof(int));

    fill(arr, size, argv);

    printf("Before sorting: ");
    print_arr(arr, size);

    selection_sort(arr, size);

    printf("After sorting:  ");
    print_arr(arr, size);

    free(arr);
    return EXIT_SUCCESS;
}