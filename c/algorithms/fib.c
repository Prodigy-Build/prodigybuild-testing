#include <stdio.h>

int binsearch(int arr[], int n, int elem) {
    int start = 0, end = n - 1; 
    while (start <= end) { 
        int mid = (start + end) / 2; 
   
        if (arr[mid] == elem) 
            return mid; 
  
        if (arr[mid] < elem) 
            start = mid + 1; 
  
        else
            end = mid - 1; 
    } 
   
    return -1; 
}

int main(int argc, char *argv[]) { 
    int arr[10] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int elem = atoi(argv[1]); 
    int result = binsearch(arr, n, elem);
    (result == -1) ? printf("Element is not present in array\n") :printf("Element is present at index %d\n", result); 
    return 0; 
}