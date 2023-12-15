#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int len, int element)
{
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (yarr[mid] == element) {
            return mid;
        }

        if (yarr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int len = sizeof(unsorted) / sizeof(unsorted[0]);

    // Perform sorting algorithm here if needed

    int element = 4;
    int index = binsearch(unsorted, len, element);

    if (index != -1) {
        printf("Element %d found at index %d\n", element, index);
    } else {
        printf("Element %d not found\n", element);
    }

    return 0;
}