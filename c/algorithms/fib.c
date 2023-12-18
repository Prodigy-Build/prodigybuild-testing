#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(int) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(int) - 1;

    if (element == yarr[mid])
    {
        return mid;
    }

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (yarr[mid] == element)
        {
            return mid;
        }

        if (yarr[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

void test_binsearch()
{
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // Test cases
    assert(binsearch(arr, 1) == 0);
    assert(binsearch(arr, 9) == 4);
    assert(binsearch(arr, 19) == 9);
    assert(binsearch(arr, 20) == -1);
    assert(binsearch(arr, -1) == -1);
    assert(binsearch(arr, 10) == -1);
}

int main(int argc, char *argv[])
{
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int element = atoi(argv[1]);
    int result = binsearch(arr, element);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    test_binsearch();

    return 0;
}