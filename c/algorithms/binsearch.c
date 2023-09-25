#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (yarr[mid] == element)
        {
            return mid;
        }
        else if (yarr[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void test_binsearch()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Test cases
    printf("%d\n", binsearch(arr, size, 3)); // Expected output: 2
    printf("%d\n", binsearch(arr, size, 6)); // Expected output: -1
    printf("%d\n", binsearch(arr, size, 1)); // Expected output: 0
}

int main()
{
    test_binsearch();

    return 0;
}