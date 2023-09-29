#include <stdio.h>
#include <stdbool.h>

bool linsearch(int *yarr, int val, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return true;
        }    
    }
    return false;
}

int main()
{
    int yarr[] = {1, 2, 3, 4, 5};
    int val = 3;
    int size = sizeof(yarr) / sizeof(yarr[0]);
    linsearch(yarr, val, size);
}