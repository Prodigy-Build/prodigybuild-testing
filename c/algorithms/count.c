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

void test_count()
{
    int num;
    
    // Test case 1
    num = 5;
    count(num);
    // Expected output: [01234]
    
    // Test case 2
    num = 30;
    count(num);
    // Expected output: 
    // [
    // 0, 
    // 1, 
    // 2, 
    // ...
    // 29, 
    // 30
    // ]
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    
    // Run unit tests
    test_count();
    
    return 0;
}