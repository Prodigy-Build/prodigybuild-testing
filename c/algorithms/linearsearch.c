#include <stdio.h>

int linsearch(int *yarr, int val, int size)
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
    int yarr[] = {5, 10, 15, 20, 25};
    int val = 15;
    int size = sizeof(yarr) / sizeof(yarr[0]);
    linsearch(yarr, val, size);
}