#include <stdio.h>

int binsearch(int yarr[], int element) {
    int left = 0;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(yarr[mid] == element) {
            return mid;
        }
        
        if(yarr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// Unit test cases
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    printf("%d\n", binsearch(arr, 5)); // Expected output: 4
    printf("%d\n", binsearch(arr, 2)); // Expected output: 1
    printf("%d\n", binsearch(arr, 6)); // Expected output: -1
    
    return 0;
}