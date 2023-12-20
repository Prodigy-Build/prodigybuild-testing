#include <stdio.h>

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

int main(int argc, char *argv[])
{
    // Test input
    int yarr[] = {1, 3, 5, 7, 9};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int element = 5;
    
    // Call binsearch function
    int result = binsearch(yarr, size, element);
    
    // Print result
    printf("Element found at index: %d\n", result);
    
    return 0;
}