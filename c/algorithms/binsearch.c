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

// Unit test cases
int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Test case 1: Finding an existing element (10) in the array
    int element1 = 10;
    int index1 = binsearch(arr, size, element1);
    
    // Test case 2: Finding a non-existing element (7) in the array
    int element2 = 7;
    int index2 = binsearch(arr, size, element2);
    
    // Printing the results
    printf("Test case 1: Element %d found at index %d\n", element1, index1);
    printf("Test case 2: Element %d not found\n", element2);
    
    return 0;
}