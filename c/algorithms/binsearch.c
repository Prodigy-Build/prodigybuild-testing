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

// Unit Test Cases
void test() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Element present in the array
    int index = binsearch(arr, size, 12);
    printf("Index of element 12: %d\n", index);
    
    // Element not present in the array
    index = binsearch(arr, size, 5);
    printf("Index of element 5: %d\n", index);
}

int main() {
    test();
    
    return 0;
}