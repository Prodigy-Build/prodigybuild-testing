The updated file "c/algorithms/linearsearch.c" with unit tests is as follows:

#include <stdio.h>
#include <stdbool.h>
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
    int yarr[2] = {"Shluck much", "much Shluck"};

    assert(linsearch(yarr, "Shluck much") == 0);
    assert(linsearch(yarr, "much Shluck") == 0);
    assert(linsearch(yarr, "not found") == 1);
}

int main()
{
    test_linsearch();
    
    return 0;
}