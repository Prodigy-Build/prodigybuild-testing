#include <stdio.h>

int linsearch(int *arr, int len, int val)
{
    for(int i = 0; i < len; i++)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr)/sizeof(arr[0]);
    int val = 5;
    int idx = linsearch(arr, len, val);
    if (idx != -1)
        printf("Element found at index: %d", idx);
    else
        printf("Element not found");
    
    return 0;
}