#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int size = sizeof(yarr) / sizeof(int);
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
    int yarr[] = {42, 23};
    int val = 42;
    linsearch(yarr, val);
}