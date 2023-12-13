#include <stdio.h>

void binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(int) / 2;
    int left = mid;
    int right = 10 - mid;
    
    if(element == yarr[mid])
    printf("%d\n", yarr[mid]);
    
    if(element != yarr[right])
    {
        for(int i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
            //Does this so that it doesn't print multiple times
            printf("%d\n", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = atoi(argv[1]);
    binsearch(arr, element);
    return 0;
}