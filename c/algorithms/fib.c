#include <stdio.h>
#include <stdlib.h>

int binsearch(int yarr[], int size, int element)
{
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    
    if (element == yarr[mid])
    {
        printf("%d\n", element);
    }
    if (element != yarr[right])
    {
        for (int i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                printf("%d\n", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[10];
    int yarrSize = sizeof(yarr) / sizeof(int);
    // Initialize yarr with desired values
    
    int element = atoi(argv[1]);
    binsearch(yarr, yarrSize, element);
    
    return 0;
}