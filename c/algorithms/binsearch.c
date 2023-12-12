#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (yarr[mid] == element)
        {
            return mid;
        }
        
        if (yarr[mid] < element)
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

void test_binsearch()
{
    int yarr[] = {2, 4, 6, 8, 10};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    
    printf("Testing binsearch...\n");
    
    // Test case 1: Element in the array
    int result1 = binsearch(yarr, size, 6);
    printf("Expected: 2, Actual: %d\n", result1);
    
    // Test case 2: Element not in the array
    int result2 = binsearch(yarr, size, 5);
    printf("Expected: -1, Actual: %d\n", result2);
    
    // Test case 3: Empty array
    int empty_arr[] = {};
    int result3 = binsearch(empty_arr, 0, 5);
    printf("Expected: -1, Actual: %d\n", result3);
}

int main()
{
    test_binsearch();
    
    return 0;
}