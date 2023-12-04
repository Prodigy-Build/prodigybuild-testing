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
    int yarr[] = {1, 2, 3, 4};
    int val = 3;
    linsearch(yarr, val);
}