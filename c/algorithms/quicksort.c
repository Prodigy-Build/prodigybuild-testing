#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binsearch(int arr[], int size, int element);

void test_binsearch()
{
    // Test case 1
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int element1 = 3;
    int expected1 = 2;
    int result1 = binsearch(arr1, size1, element1);
    printf("Test case 1: %s\n", result1 == expected1 ? "Pass" : "Fail");

    // Test case 2
    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int element2 = 6;
    int expected2 = -1;
    int result2 = binsearch(arr2, size2, element2);
    printf("Test case 2: %s\n", result2 == expected2 ? "Pass" : "Fail");

    // Test case 3
    int arr3[] = {1, 2, 3, 3, 4, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int element3 = 3;
    int expected3 = 2;
    int result3 = binsearch(arr3, size3, element3);
    printf("Test case 3: %s\n", result3 == expected3 ? "Pass" : "Fail");
}

int main()
{
    test_binsearch();
    return 0;
}

int binsearch(int arr[], int size, int element)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
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