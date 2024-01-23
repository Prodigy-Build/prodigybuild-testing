#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid;
    int left = 0;
    int right = 9;

    while (left <= right) 
    {
        mid = left + (right - left) / 2;
        if (yarr[mid] == element)
        {
            printf("%d found at index %d\n", element, mid);
            return mid;
        }
        if (yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("%d not found in array\n", element);
    return -1;
}

int main(int argc, char *argv[])
{
    int yarr[10] = {10, 22, 35, 47, 55, 67, 82, 98, 109, 131};
    int element = atoi(argv[1]);
    binsearch(yarr, element);
    return 0;
}