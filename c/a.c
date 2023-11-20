#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = sizeof(yarr) - left;
    extern int i;
    
    if(element == yarr[mid])
        return mid;
    
    for(i = 0; i < left; i++)
    {
        if(element == yarr[i])
            return i;
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int result = binsearch(arr, 5);
    
    if(result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");
    
    return 0;
}