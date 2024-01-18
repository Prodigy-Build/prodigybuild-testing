#include <stdio.h>

int binsearch(int yarr[], int n, int element)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (yarr[mid] == element)
            return mid;
        if (yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("Insufficient arguments provided\n");
        return 1;
    }

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = atoi(argv[1]);
    int result = binsearch(arr, n, x);
    (result == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result);
    return 0;
}