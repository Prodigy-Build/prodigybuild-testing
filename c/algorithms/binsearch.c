#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

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

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", binsearch(arr, size, 1));
    printf("%d\n", binsearch(arr, size, 5));
    printf("%d\n", binsearch(arr, size, 9));
    printf("%d\n", binsearch(arr, size, 2));

    return 0;
}