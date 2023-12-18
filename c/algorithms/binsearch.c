#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int left = 0;
    int right = 9;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (yarr[mid] == element) {
            return mid;
        }

        if (yarr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void test_binsearch()
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Test case 1: element found in array
    int element1 = 5;
    int expected1 = 4;
    int result1 = binsearch(yarr, element1);
    if (result1 == expected1) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
    }

    // Test case 2: element not found in array
    int element2 = 11;
    int expected2 = -1;
    int result2 = binsearch(yarr, element2);
    if (result2 == expected2) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
    }
}

int main()
{
    test_binsearch();
    return 0;
}