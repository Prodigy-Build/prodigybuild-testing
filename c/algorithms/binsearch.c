#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = 10 - mid;
    int i;

    if (element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }
    
    if (element != yarr[right])
    {
        for (i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                //Does this so that it doesn't print multiple times
                printf("%d", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[10];
    int element;

    // Test 1
    yarr[0] = 1;
    yarr[1] = 2;
    yarr[2] = 3;
    yarr[3] = 4;
    yarr[4] = 5;
    yarr[5] = 6;
    yarr[6] = 7;
    yarr[7] = 8;
    yarr[8] = 9;
    yarr[9] = 10;
    element = 5;
    binsearch(yarr, element);

    // Test 2
    yarr[0] = 1;
    yarr[1] = 2;
    yarr[2] = 3;
    yarr[3] = 4;
    yarr[4] = 5;
    yarr[5] = 6;
    yarr[6] = 7;
    yarr[7] = 8;
    yarr[8] = 9;
    yarr[9] = 10;
    element = 11;
    binsearch(yarr, element);

    return 0;
}