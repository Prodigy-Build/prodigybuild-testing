/* Refactored code */

#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid - 1;
    int right = mid + 1;

    if (element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }

    if (element != yarr[right])
    {
        for (int i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                printf("%d", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = atoi(argv[1]);

    binsearch(arr, element);
}