#include <stdio.h>
#include <stdbool.h>

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
    int yarr[] = {10, 20, 30, 40, 50};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    
    int result = linsearch(yarr, 30, size);
    if(result == 2)
    {
        printf("Test case 1 Passed\n");
    }
    else
    {
        printf("Test case 1 Failed\n");
    }

    result = linsearch(yarr, 100, size);
    if(result == -1)
    {
        printf("Test case 2 Passed\n");
    }
    else
    {
        printf("Test case 2 Failed\n");
    }
}

int main()
{
    test_linsearch();
    return 0;
}