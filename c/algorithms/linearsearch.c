#include <stdio.h>
#include <stdbool.h>

int linsearch(int *yarr, int size, int val)
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
    int size = sizeof(yarr) / sizeof(yarr[0]);
    
    // Test case 1: Element exists in the array
    int val1 = 3;
    int expected1 = 2;
    int result1 = linsearch(yarr, size, val1);
    printf("Test case 1: %s\n", expected1 == result1 ? "Passed" : "Failed");
    
    // Test case 2: Element does not exist in the array
    int val2 = 6;
    int expected2 = -1;
    int result2 = linsearch(yarr, size, val2);
    printf("Test case 2: %s\n", expected2 == result2 ? "Passed" : "Failed");
}

int main()
{
    test_linsearch();
    return 0;
}