#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count from 0 up to the provided number
int count(int num) 
{
    printf("["); // Starts printing output within brackets
    
    if(num > 20) // Controls the format of the output depending on the input number
    {
        int i;
        // Loop to print each number on a new line when input number is greater than 20
        for(i = 0; i < num; i++) 
            printf("\n%d, \n", i);
            
        // Closes the bracket when loop has completed
        if(i == num + 1)
            printf("]");
    } else
    {
        int i;
        // Loop to print each number in line when the input number is 20 or less
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        // Closes the bracket when loop has completed
        if(i == num)
            printf("]");
    }
}

// Main function that asks for input from user
int main()
{
    int num;
    printf("Count:~$ "); // Prompt user to input number
    scanf("%d", &num); // Scans the input number
    count(num); // Executes the count function with the input number
}