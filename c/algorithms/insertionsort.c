#include <stdio.h>

void insertionSort(int unsorted[], int n) { 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = unsorted[i]; 
        j = i - 1; 
  
        while (j >= 0 && unsorted[j] > key) { 
            unsorted[j + 1] = unsorted[j]; 
            j = j - 1; 
        } 
        unsorted[j + 1] = key; 
    } 
}

int main() {
    int unsorted[] = {5, 6, 4, 3, 9};
    int n = sizeof(unsorted)/sizeof(unsorted[0]);
    insertionSort(unsorted, n);
   
    return 0; 
}