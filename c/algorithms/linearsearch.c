#include <stdio.h>
#include <stdbool.h>

bool linsearch(int *yarr, int size, int val)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return true;
        }    
    }
    return false;
}

int main()
{
    int yarr[] = {1, 2, 3, 4, 5};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int val = 3;
    bool result = linsearch(yarr, size, val);
    printf("Result: %s\n", result ? "true" : "false");
    return 0;
}