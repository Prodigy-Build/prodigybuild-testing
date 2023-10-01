#include <stdio.h>
#include <stdbool.h>

/* Function to perform binary search 
   Returns true if element is found, false otherwise */
bool binsearch(int yarr[], int n, int element)
{
    int left = 0;
    int right = n - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        // Check if element is present at mid
        if (yarr[mid] == element)
            return true;
        
        // If element greater, ignore left half
        if (yarr[mid] < element)
            left = mid + 1;
        
        // If element is smaller, ignore right half
        else
            right = mid - 1;
    }
    
    // Element is not present
    return false;
}

int main(int argc, char *argv[])
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(yarr) / sizeof(yarr[0]);
    int element = 5;

    bool result = binsearch(yarr, n, element);
    
    printf("Result: %s\n", result ? "true" : "false");
    
    return 0;
}