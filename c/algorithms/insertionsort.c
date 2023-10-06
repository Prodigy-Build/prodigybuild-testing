#include <stdio.h>
#include <assert.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

int main() {
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[] = {3, 4, 5, 6, 9};
    
    int n = sizeof(unsorted) / sizeof(unsorted[0]);
    
    insertionSort(unsorted, n);
    
    for (int i = 0; i < n; i++) {
        assert(unsorted[i] == sorted[i]);
    }
    
    printf("All test cases passed!\n");
    
    return 0;
}