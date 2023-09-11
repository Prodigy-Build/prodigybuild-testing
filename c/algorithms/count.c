#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count from 0 to num
int count(int num) 
{
    // Start output with [
    printf("[");

    // If num is greater than 20, then print each number on a new line 
    if(num > 20)
    {
        int i;
        // Loop and print each number from 0 to num
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        // Print closing ] at the end
        if(i == num + 1)
            printf("]");
    } else // If num is less than or equal to 20 then print each number on same line
    {
        int i;
        // Loop and print each number from 0 to num
        for(i = 0; i < num; i++)
            printf("%d", i);
        
        // Print closing ] at the end
        if(i == num)
            printf("]");
    }
}

// The main program begins here
int main()
{
    int num; // Variable to hold input number
    printf("Count:~$ ");
    // Read input from user
    scanf("%d", &num);
    // Call count function with input number
    count(num);
}