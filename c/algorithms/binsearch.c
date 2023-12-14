#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = (sizeof(yarr) / sizeof(yarr[0]) - 1) / 2;
    int right = (sizeof(yarr) / sizeof(yarr[0])) - 1 - left;
    int i;

    if (element == yarr[mid])
        printf("%d", mid);

    if (element != yarr[right])
    {
        for (i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 4;

    binsearch(yarr, element);
}