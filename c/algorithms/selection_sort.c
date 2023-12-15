#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

void print_arr(int *ptr, int size)
{
    putchar('[');
    while (size--)
    {
        printf("%d", *ptr++);
        if (size)
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
    while (size--)
    {
        if (*ptr < *min)
            min = ptr;
        ptr++;
    }
    return (min);
}

void selection_sort(int *ptr, int size)
{
    int *min;

    while (--size)
    {
        if ((min = find_min(ptr + 1, size)))
        {
            if (*ptr > *min)
                swap(ptr, min);
        }
        ptr++;
    }
}

void fill(char **av, int *ptr, int size)
{
    int i;

    i = 2;
    while (av[i] && size--)
        *ptr++ = atoi(av[i++]);
}

CTEST(Arrays, SelectionSort)
{
    int arr[] = {3, 2, 1, 0};
    int expected[] = {0, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, size);

    ASSERT_EQUAL_DATA(expected, arr, size * sizeof(arr[0]));
}

CTEST(Arrays, Swap)
{
    int a = 5;
    int b = 10;
    int expected_a = 10;
    int expected_b = 5;

    swap(&a, &b);

    ASSERT_EQUAL(expected_a, a);
    ASSERT_EQUAL(expected_b, b);
}

CTEST(Arrays, FindMin)
{
    int arr[] = {2, 5, 3, 7};
    int *expected = &arr[0];
    int size = sizeof(arr) / sizeof(arr[0]);

    int *actual = find_min(arr, size);

    ASSERT_EQUAL(expected, actual);
}

CTEST(Arrays, PrintArr)
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    freopen("output.txt", "w", stdout);
    print_arr(arr, size);
    fclose(stdout);

    FILE *output_file = fopen("output.txt", "r");
    char output[20];
    fgets(output, sizeof(output), output_file);
    fclose(output_file);

    ASSERT_STR("1,2,3,4,5\n", output);
}

CTEST(Arrays, Fill)
{
    int arr[4];
    char *data[] = {"./your-executable-name", "4", "1", "2", "3"};

    fill(data, arr, 4);

    ASSERT_EQUAL(1, arr[0]);
    ASSERT_EQUAL(2, arr[1]);
    ASSERT_EQUAL(3, arr[2]);
    ASSERT_EQUAL(0, arr[3]);
}

CTEST(Arrays, Main)
{
    char *data[] = {"./your-executable-name", "4", "1", "2", "3"};
    freopen("output.txt", "w", stdout);
    main(5, data);
    fclose(stdout);

    FILE *output_file = fopen("output.txt", "r");
    char output[100];
    fgets(output, sizeof(output), output_file);
    fclose(output_file);

    ASSERT_STR("Before sorting: [1,2,3,0]\nAfter sorting:  [0,1,2,3]\n", output);
}