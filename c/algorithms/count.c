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

// Unit Test 1
void test1() {
    count(10);
    // Expected output: [0123456789]
}

// Unit Test 2
void test2() {
    count(26);
    // Expected output: [0, 
    //1, 
    //2, 
    //...
    //23, 
    //24, 
    //25, 
    //]
}

int main()
{
    // Run unit tests
    test1();
    test2();
    
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}