// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Defines a function that counts numbers from 0 to input num
int count(int num) 
{
    // Indicate the start of the array
    printf("[");

    // Initialize a loop counter
    int i;

    // For loop to iterate from 0 to num
    for(i = 0; i < num; i++)
    {
        // Check if the num is greater than 20
        if(num > 20)
        {
            // Print number with formatting for longer lists
            printf("\n%d, \n", i);
        }
        else 
        {
            // Print number without formatting for shorter lists
            printf("%d", i);
        }
        
        // Check if we've reached the end of our count
        if(i == num - 1)
        {
            // Close the array
            printf("]");
        }
    }
}

// Main function
int main()
{
    // Initialize a number to count
    int num;

    // Ask the user for input
    printf("Count:~$ ");
    scanf("%d", &num);

    // Call the count function with the user's input
    count(num);
}