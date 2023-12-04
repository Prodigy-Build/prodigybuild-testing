#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - left;
    extern int i;
    
    if(element == yarr[mid])
    printf("%d", &yarr[mid]);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
            //Does this so that it doesn't print multiple times
            printf("%d", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[10];
    sscanf(argv[1], "%d", &arr[0]);
    sscanf(argv[2], "%d", &arr[1]);
    binsearch(arr, arr[1]);
    return 0;
}