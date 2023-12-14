#include <stdio.h>

// Function to perform linear search
int linsearch(int *yarr, int val)
{
    for(int i = 0; i < sizeof(yarr); i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }    
        else
        {
          return 1;
        }
    }
}

// Unit tests
int main()
{
    // Test Case 1: Element found in array
    int arr1[] = {10, 20, 30, 40, 50};
    int searchVal1 = 30;
    int result1 = linsearch(arr1, searchVal1);
    printf("Test Case 1: %d\n", result1); // Expected output: 0
    
    // Test Case 2: Element not found in array
    int arr2[] = {10, 20, 30, 40, 50};
    int searchVal2 = 60;
    int result2 = linsearch(arr2, searchVal2);
    printf("Test Case 2: %d\n", result2); // Expected output: 1
    
    // Test Case 3: Empty array
    int arr3[] = {};
    int searchVal3 = 30;
    int result3 = linsearch(arr3, searchVal3);
    printf("Test Case 3: %d\n", result3); // Expected output: 1

    return 0;
}