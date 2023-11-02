#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = sizeof(yarr) - left;
    extern int i;
    
    if(element == yarr[mid])
        printf("%d", yarr[mid]);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[10];
    int i;
    
    for(i = 0; i < argc - 2; i++)
    {
        arr[i] = atoi(argv[i+2]);
    }
    
    binsearch(arr, argc - 2);
    return 0;
}