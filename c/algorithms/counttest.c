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
    } else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
}

// Unit test cases
void test_count()
{
  // Test case 1: num is less than 20
  count(5); // Expected output: [01234]

  // Test case 2: num is equal to 20
  count(20); // Expected output: [012345678910111213141516171819]

  // Test case 3: num is greater than 20
  count(25); // Expected output: 
  /*
  0, 
  1, 
  2, 
  3, 
  4, 
  5, 
  6, 
  7, 
  8, 
  9, 
  10, 
  11, 
  12, 
  13, 
  14, 
  15, 
  16, 
  17, 
  18, 
  19, 
  20, 
  21, 
  22, 
  23, 
  24, 
  ] 
  */
}

int main()
{
    // Run unit test cases
    test_count();
    
    return 0;
}