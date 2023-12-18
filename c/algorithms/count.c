#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Function to print count from 0 to num
void count(int num) 
{
    printf("[");
    
    if(num > 20) 
    {
        for(int i = 0; i < num; i++)
        {
            printf("\n%d, \n", i);
        }
            
        printf("]");
    } 
    else 
    {
        for(int i = 0; i < num; i++)
        {
            printf("%d", i);
        }
            
        printf("]");
    }
}

// Unit Test Cases
void testCount() {
    printf("Test Case 1\n");
    printf("Expected Output : [0, 1, 2, 3, 4, ...]\n");
    printf("Actual Output   : ");
    count(10);
    printf("\n\n");
    
    printf("Test Case 2\n");
    printf("Expected Output : [0, 1, 2, ... 19]\n");
    printf("Actual Output   : ");
    count(20);
    printf("\n\n");
    
    printf("Test Case 3\n");
    printf("Expected Output : [0, 1, 2, 3, 4, ... 99]\n");
    printf("Actual Output   : ");
    count(100);
    printf("\n\n");
}

int main()
{
    testCount();
    
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    
    return 0;
}