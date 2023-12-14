#include <stdio.h>

int linsearch(int *yarr, int val)
{
    for(int i = 0; i < sizeof(yarr) / sizeof(yarr[0]); i++)
    {
        if(yarr[i] == val)
        {
            return 1;
        }    
    }
    
    return 0;
}

int main()
{
    int yarr[] = {4, 8, 15, 16, 23, 42};
    int val = 42;
    linsearch(yarr, val);
}