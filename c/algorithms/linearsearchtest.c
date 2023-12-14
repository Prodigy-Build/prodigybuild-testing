#include <stdio.h>
#include <stdbool.h> // for bool data type

int linsearch(int *yarr, int size, int val)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }    
    }
    
    return 1;
}

void runTests()
{
    // Test Case 1: Element is present in the array
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int val1 = 3;
    bool result1 = (linsearch(arr1, size1, val1) == 0);
    printf("Test Case 1: %s\n", result1 ? "Passed" : "Failed");
    
    // Test Case 2: Element is not present in the array
    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int val2 = 6;
    bool result2 = (linsearch(arr2, size2, val2) == 1);
    printf("Test Case 2: %s\n", result2 ? "Passed" : "Failed");
    
    // Test Case 3: Empty array
    int arr3[] = {};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int val3 = 5;
    bool result3 = (linsearch(arr3, size3, val3) == 1);
    printf("Test Case 3: %s\n", result3 ? "Passed" : "Failed");
}

int main()
{
    // Run the tests
    runTests();
    
    return 0;
}