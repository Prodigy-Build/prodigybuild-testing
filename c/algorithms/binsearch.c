#include <stdio.h>

int binsearch(int yarr[10], int element) {
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = 0;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;

    if (element == yarr[mid]) {
        printf("%d", yarr[mid]);
    }
    
    if (element != yarr[right]) {
        for (int i = 0; i <= left; i++) {
            if (element == yarr[i]) {
                printf("%d", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int arr[10];
    
    // Assign arguments to array
    for (int i = 0; i < argc - 2; i++) {
        arr[i] = atoi(argv[i + 2]);
    }

    binsearch(arr, atoi(argv[1]));
}