#include <stdio.h>

int binsearch(int yarr[], int size, int element) {
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    extern int i;
    
    if (element == yarr[mid]) {
        printf("%d\n", mid);
    }
    
    if (element != yarr[right]) {
        for (i = 0; i < left; i++) {
            if (element == yarr[i]) {
                printf("%d\n", i);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    binsearch(arr, size, 5);
}