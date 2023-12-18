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
    char *yarr[] = {"Shluck much", "much Shluck"};
    char *val = "Shluck Much";
    int size = sizeof(yarr) / sizeof(yarr[0]);
    linsearch(yarr, val, size);
}