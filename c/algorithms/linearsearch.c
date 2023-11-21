#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int size = sizeof(yarr) / sizeof(yarr[0]);
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
    int result = linsearch(yarr, val);
    printf("%d\n", result);
    return 0;
}