#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int yarr[] = {1, 2, 3, 4, 5};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int val = 3;
    int result = linsearch(yarr, size, val);
    
    if(result == 0)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
    
    return 0;
}