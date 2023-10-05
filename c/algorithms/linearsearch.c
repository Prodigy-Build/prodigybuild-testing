#include <stdio.h>

int linsearch(int *yarr, int val)
{
    for(int i = 0; i < sizeof(yarr); i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }    
        else
        {
          return 1;
        }
    }
}

int main()
{
    char *yarr[] = {"Shluck much", "much Shluck"};
    char *val = "Shluck Much";
    linsearch(yarr, val);
    return 0;
}