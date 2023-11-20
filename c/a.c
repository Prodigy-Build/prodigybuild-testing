#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element) {
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]);
    extern int i;
    
    if(element == yarr[mid]) {
        printf("%d\n", yarr[mid]);
    }
    
    if(element != yarr[right]) {
        for(i = 0; i < left; i++) {
            if(element == yarr[i]) {
                //Does this so that it doesn't print multiple times
                printf("%d\n", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    binsearch(arr, 7);
    binsearch(arr, 11);
    binsearch(arr, 20);
    return 0;
}