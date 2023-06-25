

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

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}

// Unit Test
void test_count() {
    int num = 10;
    int expected_result = 10;
    int actual_result = count(num);
    assert(expected_result == actual_result);
}

int main()
{
    test_count();
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}