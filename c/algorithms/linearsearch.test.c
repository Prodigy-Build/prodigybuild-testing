#include <stdio.h>
#include <stdbool.h>

int linsearch(int *yarr, int val)
{
    for(int i = 0; i < sizeof(yarr); i++)
    {
        if(yarr[i] == val)
        {
            return i;
        }    
    }
    return -1;
}

bool test_linsearch()
{
    int yarr[5] = {1, 2, 3, 4, 5};
    
    if(linsearch(yarr, 1) != 0)
        return false;
    
    if(linsearch(yarr, 6) != -1)
        return false;
    
    return true;
}

int main()
{
    int yarr[] = {1, 2, 3, 4, 5};
    int val = 3;
    int result = linsearch(yarr, val);
    printf("Index of %d: %d\n", val, result);
    
    bool test_result = test_linsearch();
    printf("Unit Test Result: %s\n", test_result ? "Pass" : "Fail");
    
    return 0;
}