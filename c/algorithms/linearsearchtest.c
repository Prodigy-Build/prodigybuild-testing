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

void test_linsearch()
{
    // Test case 1: yarr contains the value
    int yarr1[] = {1, 2, 3, 4, 5};
    int val1 = 3;
    int result1 = linsearch(yarr1, val1);
    printf("Test case 1: %d\n", result1);  // Expected output: 0
    
    // Test case 2: yarr does not contain the value
    int yarr2[] = {1, 2, 3, 4, 5};
    int val2 = 6;
    int result2 = linsearch(yarr2, val2);
    printf("Test case 2: %d\n", result2);  // Expected output: 1
}

int main()
{
    test_linsearch();
    return 0;
}