#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Function to perform binary search on array for a given element
int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

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

// Unit Test 1: Test binsearch function with an empty array
void test_binsearch_empty_array()
{
    int arr[] = {};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 5;
    int result = binsearch(arr, size, element);
    printf("Result: %d\n", result); // Expected output: -1
}

// Unit Test 2: Test binsearch function with an array containing the element
void test_binsearch_element_exists()
{
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 5;
    int result = binsearch(arr, size, element);
    printf("Result: %d\n", result); // Expected output: 2
}

// Unit Test 3: Test binsearch function with an array not containing the element
void test_binsearch_element_not_exists()
{
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 8;
    int result = binsearch(arr, size, element);
    printf("Result: %d\n", result); // Expected output: -1
}

int main()
{
    test_binsearch_empty_array();
    test_binsearch_element_exists();
    test_binsearch_element_not_exists();
}