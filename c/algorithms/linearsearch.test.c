#include <stdio.h>
#include <stdbool.h>

int linsearch(int *yarr, int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (yarr[i] == val)
        {
            return 0;
        }
    }
    return 1;
}

void test_linsearch()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Test case 1: successful search
    int result = linsearch(arr, size, 3);
    printf("Test case 1: %d\n", result);

    // Test case 2: unsuccessful search
    result = linsearch(arr, size, 6);
    printf("Test case 2: %d\n", result);
}

int main()
{
    test_linsearch();

    return 0;
}