#include <stdio.h>

int linsearch(const int *yarr, int size, int val)
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
    const int yarr[] = {1, 2, 3, 4, 5};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int val = 3;
    linsearch(yarr, size, val);
}