#include <stdio.h>

int binsearch(int yarr[], int size, int element) {
    int mid = size / 2;
    int left = mid;
    int right = size - 1;
    int i;
    
    if (element == yarr[mid]) {
        printf("%d", element);
    }
    
    if (element != yarr[right]) {
        for (i = 0; i < left; i++) {
            if (element == yarr[i]) {
                printf("%d", element);
                break;
            }
        }
    }
}

void test_binsearch() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test element in the middle of the array
    binsearch(arr, 10, 5); // Expected output: 5
    
    // Test element not in the middle but in the array
    binsearch(arr, 10, 3); // Expected output: 3
    
    // Test element not in the array
    binsearch(arr, 10, 11); // Expected output: no output
}

int main() {
    test_binsearch();
    return 0;
}