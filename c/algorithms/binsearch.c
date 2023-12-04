```c
#include <stdio.h>

int binsearch(int yarr[10], int element) {
    int mid = 10 / 2;
    int left = mid;
    int right = 10 - left;
    extern int i;

    if (element == yarr[mid]) {
        printf("%d", mid);
    }

    if (element != yarr[right]) {
        for (i = 0; i < left; i++) {
            if (element == yarr[i]) {
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = atoi(argv[i]);
    }
    binsearch(arr, atoi(argv[10]));
    return 0;
}
```