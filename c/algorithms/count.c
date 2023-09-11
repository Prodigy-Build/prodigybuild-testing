#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count from 0 up to a given number
int count(int num) 
{
    printf("[");
    
    // If number is greater than 20, print each number on a new line
    if(num > 20)
    {
        int i;
        // Loop from 0 to number-1
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        // Print closing bracket at the end of count
        if(i == num + 1)
            printf("]");
    } 
    else
    {
        int i;
        // If number is 20 or less, print the numbers inline
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        // Print closing bracket at the end of count
        if(i == num)
            printf("]");
    }
}

int main()
{
    int num;
    printf("Count:~$ ");
    // Get the number to count up to from user
    scanf("%d", &num);
    // Call count function
    count(num);
}