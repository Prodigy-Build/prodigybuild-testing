#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = 0;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    
    if(element == yarr[mid])
    {
        printf("%d", mid);
    }
    
    if(element != yarr[right])
    {
        for(int i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[argc-1];
    for(int i = 1; i < argc; i++)
    {
        arr[i-1] = atoi(argv[i]);
    }
    
    binsearch(arr, atoi(argv[1]));
}