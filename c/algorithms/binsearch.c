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
    int arr[argc - 1];
    
    for (int i = 1; i < argc; i++) {
        arr[i-1] = atoi(argv[i]);
    }
    
    int element = atoi(argv[argc - 1]);
    
    binsearch(arr, argc - 1, element);
    
    return 0;
}