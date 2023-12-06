#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

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
    int yarr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int element = 12;
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int result = binsearch(yarr, size, element);

    printf("Element found at index: %d\n", result);

    return 0;
}