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

void test_linsearch()
{
    int yarr[] = {"Shluck much", "much Shluck"};
    int val = "Shluck Much";
    assert(linsearch(yarr, val) == 0);
}

int main()
{
    test_linsearch();
    return 0;
}