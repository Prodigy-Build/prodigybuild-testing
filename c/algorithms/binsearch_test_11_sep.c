#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) /2;
    int left = 0;
    int right = sizeof(yarr) - 1;

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
};

int main()
{
    int yarr[] = {2, 3, 4, 10, 40};
    int element = 10;
    int element2 = 4;
    int result = binsearch(yarr, element);
    int result2 = binsearch(yarr, element2);
    (result == -1) ? printf("10 is not present in array\n")
                   : printf("10 is present at index %d\n", result);
    (result2 == -1) ? printf("4 is not present in array\n")
                   : printf("4 is present at index %d\n", result2);
    return 0;
}
