#include <stdio.h>

int binsearch(int yarr[], int length, int element) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (yarr[mid] == element) {
            return mid;
        } else if (yarr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
  
    return -1;
}

int main(int argc, char *argv[]) {
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(yarr) / sizeof(yarr[0]);
    int element = atoi(argv[1]);

    int result = binsearch(yarr, length, element);
    printf("%d", result);
  
    return 0;
}