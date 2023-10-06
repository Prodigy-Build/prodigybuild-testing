#include <stdio.h>
#include <stdbool.h>

int linsearch(int *yarr, int val, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return i;
        }    
    }
    return -1;
}

int main()
{
    int yarr[] = {1, 2, 3, 4, 5};
    int val = 3;
    int size = sizeof(yarr) / sizeof(yarr[0]);
    
    int result = linsearch(yarr, val, size);
    
    if(result != -1)
    {
        printf("Value found at index: %d\n", result);
    }
    else
    {
        printf("Value not found\n");
    }
    
    return 0;
}