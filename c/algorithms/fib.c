#include <stdio.h>
#include <stdlib.h>

int binsearch(int arr[], int size, int element)
{
    int mid = size / 2;
    int left = mid;
    int right = size - left;

    if(element == arr[mid])
    {
        printf("%d", element);
    }
    
    if(element != arr[right])
    {
        for(int i = 0; i < left; i++)
        {
            if(element == arr[i])
            {
                printf("%d", element);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[argc - 2];
    int size = argc - 2;
    
    for(int i = 0; i < size; i++)
    {
        arr[i] = atoi(argv[i + 2]);
    }
    
    int element = atoi(argv[1]);
    
    binsearch(arr, size, element);
    
    return 0;
}