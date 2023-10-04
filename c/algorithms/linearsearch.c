#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int linsearch(int *yarr, int val, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return i;
        }    
    }
    return -1;
}

void test_linsearch()
{
    int yarr[] = {1, 2, 3, 4, 5};
    int val = 3;
    int size = sizeof(yarr) / sizeof(int);
    
    assert(linsearch(yarr, val, size) == 2);
    
    int yarr2[] = {10, 20, 30, 40, 50};
    int val2 = 25;
    int size2 = sizeof(yarr2) / sizeof(int);
    
    assert(linsearch(yarr2, val2, size2) == -1);
    
    int yarr3[] = {5, 10, 15, 20};
    int val3 = 20;
    int size3 = sizeof(yarr3) / sizeof(int);
    
    assert(linsearch(yarr3, val3, size3) == 3);
}

int main()
{
    test_linsearch();
    
    return 0;
}