#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void test_count()
{
    int test_num = 5;
    count(test_num);
    // Expected output: [0, 1, 2, 3, 4, 5]
    
    test_num = 15;
    count(test_num);
    // Expected output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
    
    test_num = 25;
    count(test_num);
    // Expected output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]
}

int count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i <= num; i++)
            printf("\n%d, \n", i);
            
        // Verify if i equals num
        if(i == num + 1)
            printf("]");
    } 
    else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
        
        // Verify if i equals num
        if(i == num)
            printf("]");
    }
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    
    // Call unit test cases
    test_count();
}
