#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to print numbers from 0 to input number
int count(int num) 
{
    printf("["); // Start with a "["

    // Declare an integer i for loop
    int i;

    // Loop from 0 to num (exclusive)
    for(i = 0; i < num; i++)
    {
        // If num > 20 print numbers in a new line
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        // Else, print numbers in the same line
        else 
        {
            printf("%d", i);
        }

        // If i is the last element, print a "]"
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

// Main function to run the program
int main()
{
    int num; // Declare an integer num to hold the input

    // Print the prompt for input
    printf("Count:~$ ");

    // Take the input from the user
    scanf("%d", &num);

    // Call the count function
    count(num);

    return 0; // End the main function
}
