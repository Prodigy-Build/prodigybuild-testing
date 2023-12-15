#include <stdio.h>

void test_linsearch()
{
    int yarr[2] = {17, 25};
    int val1 = 17;
    int val2 = 25;

    int result1 = linsearch(yarr, val1);
    int result2 = linsearch(yarr, val2);

    // Write test assertions here
    
}

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
    test_linsearch();
    return 0;
}