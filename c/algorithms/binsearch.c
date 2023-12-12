#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[10], int element)
{
    int left = 0;
    int right = 9;

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

// Test cases
void test_binsearch() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Test case 1: Element present in the array
    int result = binsearch(arr, 6);
    printf("Test case 1: Element is present at index %d\n", result);

    // Test case 2: Element not present in the array
    result = binsearch(arr, 11);
    printf("Test case 2: Element is not present, expected -1. Got %d\n", result);
}

int main()
{
    test_binsearch();
    return 0;
}