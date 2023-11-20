#include <stdio.h>

// Unit test cases for binsearch function
void test_binsearch() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Testcase 1: element exists in the array
    int element1 = 3;
    int result1 = binsearch(arr, n, element1);
    printf("Element %d found at index %d\n", element1, result1);
    
    // Testcase 2: element doesn't exist in the array
    int element2 = 6;
    int result2 = binsearch(arr, n, element2);
    printf("Element %d not found\n", element2);
}

int binsearch(int arr[], int n, int element) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == element)
            return mid;
        
        if (arr[mid] < element)
            left = mid + 1;
        
        else
            right = mid - 1;
    }
    
    return -1;
}

int main() {
    test_binsearch();
    return 0;
}