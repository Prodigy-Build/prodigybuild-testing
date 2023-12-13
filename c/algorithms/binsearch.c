#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
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

// Unit test cases
int main()
{
    // Test case 1
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(int);
    int element1 = 3;
    int result1 = binsearch(arr1, size1, element1);
    printf("Result 1: %d\n", result1); // Expected output: 2

    // Test case 2
    int arr2[] = {11, 22, 33, 44, 55, 66};
    int size2 = sizeof(arr2) / sizeof(int);
    int element2 = 55;
    int result2 = binsearch(arr2, size2, element2);
    printf("Result 2: %d\n", result2); // Expected output: 4

    // Test case 3
    int arr3[] = {-5, -3, 0, 2, 4, 7};
    int size3 = sizeof(arr3) / sizeof(int);
    int element3 = 0;
    int result3 = binsearch(arr3, size3, element3);
    printf("Result 3: %d\n", result3); // Expected output: 2

    return 0;
}