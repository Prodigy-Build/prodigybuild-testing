#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int n, int element)
{
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (yarr[mid] == element)
            return mid;
        if (yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Unit test cases
void test_binsearch() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Element is present
    if (binsearch(arr, n, 8) == 3)
        printf("Test case 1 passed.\n");
    else
        printf("Test case 1 failed.\n");

    // Element is not present
    if (binsearch(arr, n, 7) == -1)
        printf("Test case 2 passed.\n");
    else
        printf("Test case 2 failed.\n");

    // Element is at the beginning
    if (binsearch(arr, n, 2) == 0)
        printf("Test case 3 passed.\n");
    else
        printf("Test case 3 failed.\n");

    // Element is at the end
    if (binsearch(arr, n, 20) == 9)
        printf("Test case 4 passed.\n");
    else
        printf("Test case 4 failed.\n");
}

int main()
{
    test_binsearch();

    return 0;
}