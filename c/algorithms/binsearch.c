#include <stdio.h>

int binsearch(int yarr[], int n, int element)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (yarr[mid] == element)
        {
            return mid;
        }
        if (yarr[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
};

int main(int argc, char *argv[])
{
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = atoi(argv[1]);
    int index = binsearch(yarr, 10, element);

    if(index != -1)
    {
        printf("Element found at index %d\n", index);
    }
    else
    {
        printf("Element not found in the array\n");
    }

    return 0;
}