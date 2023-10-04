#include <stdio.h>
#include <assert.h>

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
    int yarr[] = {1, 2, 3, 4, 5};
    int val = 3;

    assert(linsearch(yarr, val) == 0);
    
    return 0;
}