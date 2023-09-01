#include <assert.h>
#include <stdio.h>

int binsearch(int arr[], int n, int element) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == element) return mid;
        if(arr[mid] < element) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void testbinsearch() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test cases
    assert(binsearch(arr, n, 10) == 3);
    assert(binsearch(arr, n, 2) == 0);
    assert(binsearch(arr, n, 40) == 4);
    assert(binsearch(arr, n, 30) == -1);
    
    printf("All test cases pass\n");
}

int main() {
    testbinsearch();
    return 0;
}
