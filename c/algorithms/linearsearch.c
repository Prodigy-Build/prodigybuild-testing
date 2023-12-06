#include <stdio.h>
#include <stdbool.h>

bool linsearch(int *arr, int size, int val)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == val)
        {
            return true;
        }    
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int val = 3;
    bool found = linsearch(arr, size, val);
    
    if(found)
    {
        printf("The value %d is found in the array\n", val);
    }
    else
    {
        printf("The value %d is not found in the array\n", val);
    }
    
    return 0;
}