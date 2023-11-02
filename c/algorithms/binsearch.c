#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]);
    extern int i;
    
    if(element == yarr[mid])
        printf("%d", yarr[mid]);
    
    if(element != yarr[right])
    {
        for(i = 0; i < mid; i++)
        {
            if(element == yarr[i])
                printf("%d", yarr[i]);
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    binsearch(arr, 2);
    
    return 0;
}