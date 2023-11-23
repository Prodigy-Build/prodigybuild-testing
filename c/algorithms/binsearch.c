// Updated file contents with unit test cases

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
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                // Does this so that it doesn't print multiple times
                printf("%d", yarr[i]);
            }
        }
    }
}

int main(int argc, char * argv[])
{
    // Unit test cases
    int arr1[] = {1, 2, 3, 4, 5};
    binsearch(arr1, 3);
    
    int arr2[] = {10, 20, 30, 40, 50};
    binsearch(arr2, 50);
    
    return 0;
}