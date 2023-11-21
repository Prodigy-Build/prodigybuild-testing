#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        if(i == num + 1)
            printf("]");
    } 
    else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
}

void test_count()
{
    // Test case 1
    assert(count(0) == NULL);
    
    // Test case 2
    assert(count(5) == [0, 1, 2, 3, 4]);
    
    // Test case 3
    assert(count(10) == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
    
    // Test case 4
    assert(count(25) == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24]);
    
    // Additional test cases
    
    // Test case 5
    assert(count(1) == [0]);
    
    // Test case 6
    assert(count(-5) == NULL);
}

int main()
{
    test_count();
    return 0;
}