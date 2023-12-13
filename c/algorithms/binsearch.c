#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

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
    // Test case 1
    int arr1[] = {2, 3, 5, 8, 12, 14, 18, 20};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int element1 = 8;
    int expected1 = 3;
    int result1 = binsearch(arr1, size1, element1);
    printf("Test Case 1: %s\n", expected1 == result1 ? "Passed" : "Failed");

    // Test case 2
    int arr2[] = {2, 3, 5, 8, 12, 14, 18, 20};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int element2 = 14;
    int expected2 = 5;
    int result2 = binsearch(arr2, size2, element2);
    printf("Test Case 2: %s\n", expected2 == result2 ? "Passed" : "Failed");

    // Test case 3
    int arr3[] = {2, 3, 5, 8, 12, 14, 18, 20};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int element3 = 7;
    int expected3 = -1;
    int result3 = binsearch(arr3, size3, element3);
    printf("Test Case 3: %s\n", expected3 == result3 ? "Passed" : "Failed");
}

int main()
{
    test_binsearch();
    return 0;
}