```
#include <stdio.h>

// Define the function to perform binary search
int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (yarr[mid] == element)
            return mid;
        
        if (yarr[mid] < element)
            left = mid + 1;
        
        else
            right = mid - 1;
    }
    
    // Return -1 if element is not found
    return -1;
}

// Add the test cases
void runTests()
{
    // Test case 1
    int yarr1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size1 = sizeof(yarr1) / sizeof(yarr1[0]);
    int target1 = 12;
    int expected1 = 5;
    int result1 = binsearch(yarr1, size1, target1);
    printf("Test Case 1: %s\n", (result1 == expected1) ? "Passed" : "Failed");
    
    // Test case 2
    int yarr2[] = {1, 3, 5, 7, 9};
    int size2 = sizeof(yarr2) / sizeof(yarr2[0]);
    int target2 = 4;
    int expected2 = -1;
    int result2 = binsearch(yarr2, size2, target2);
    printf("Test Case 2: %s\n", (result2 == expected2) ? "Passed" : "Failed");
    
    // Test case 3
    int yarr3[] = {11, 13, 15, 17, 19, 21};
    int size3 = sizeof(yarr3) / sizeof(yarr3[0]);
    int target3 = 21;
    int expected3 = 5;
    int result3 = binsearch(yarr3, size3, target3);
    printf("Test Case 3: %s\n", (result3 == expected3) ? "Passed" : "Failed");
}

int main()
{
    runTests(); // Run the test cases
    return 0;
}
```