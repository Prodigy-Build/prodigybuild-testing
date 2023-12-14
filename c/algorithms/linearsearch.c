The updated code in the "c/algorithms/linearsearch.c" file:

#include <stdio.h>

int linsearch(int *yarr, int val)
{
    for(int i = 0; i < sizeof(yarr); i++)
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
    char *yarr[2] = {"Shluck much", "much Shluck"};
    char *val = "Shluck much";
    linsearch(yarr, val);
}