#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]);

    if(element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }

    for(int i = 0; i < left; i++)
    {
        if(element == yarr[i])
        {
            //Does this so that it doesn't print multiple times
            printf("%d", yarr[i]);
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    binsearch(arr, element);
    return 0;
}