#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
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

// Unit tests
int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Test case 1: search for existing element
    int result1 = binsearch(arr, size, 10);
    printf("Result 1: %d\n", result1);
    
    // Test case 2: search for non-existing element
    int result2 = binsearch(arr, size, 3);
    printf("Result 2: %d\n", result2);
    
    return 0;
}