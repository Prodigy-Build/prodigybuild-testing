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

// unit tests
void test_count()
{
    int num;

    printf("Test Case 1\n");
    num = 10;
    count(num); // expected output: [0123456789] (without new line character)
    
    printf("Test Case 2\n");
    num = 25;
    count(num); // expected output: [0,1,2,3,...,23,24] (with new line characters)
    
    printf("Test Case 3\n");
    num = 5;
    count(num); // expected output: [01234] (without new line character)
}

int main()
{
    // Run unit tests
    test_count();

    return 0;
}