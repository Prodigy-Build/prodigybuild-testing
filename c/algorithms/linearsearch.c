#include <stdio.h>
#include <stdbool.h>

int linsearch(int *yarr, int size, int val)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }    
    }
    return 1;
}

void test_linsearch()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    
    if(linsearch(arr1, sizeof(arr1)/sizeof(int), 3) != 0)
    {
        printf("Test case 1 failed\n");
    }
    
    if(linsearch(arr1, sizeof(arr1)/sizeof(int), 6) != 1)
    {
        printf("Test case 2 failed\n");
    }
    
    if(linsearch(arr2, sizeof(arr2)/sizeof(int), 10) != 0)
    {
        printf("Test case 3 failed\n");
    }
}

int main()
{
    test_linsearch();
    return 0;
}