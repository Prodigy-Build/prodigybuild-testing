#include <stdio.h>

int main() {
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5];
    int len = sizeof(unsorted) / sizeof(unsorted[0]);
    
    for (int i = 0; i < len; i++) {
        sorted[i] = unsorted[i];
    }
    
    for (int i = 1; i < len; i++) {
        int key = sorted[i];
        int j = i - 1;
        
        while (j >= 0 && sorted[j] > key) {
            sorted[j + 1] = sorted[j];
            j = j - 1;
        }
        sorted[j + 1] = key;
    }
    
    return 0;
}