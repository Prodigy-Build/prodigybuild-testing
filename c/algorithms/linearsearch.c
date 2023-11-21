#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int size = sizeof(yarr) / sizeof(yarr[0]);
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
    int yarr[] = {100, 200, 300, 400, 500};
    int val = 200;
    linsearch(yarr, val);
}