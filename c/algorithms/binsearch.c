#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) / sizeof(int) / 2;
    int left = mid;
    int right = mid;
    extern int i;
    
    if(element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }
    
    for(i = 0; i < left; i++)
    {
        if(element == yarr[i])
        {
            printf("%d", yarr[i]);
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[argc - 1];
    for(int i = 1; i < argc; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }
    
    binsearch(arr, atoi(argv[1]));
}