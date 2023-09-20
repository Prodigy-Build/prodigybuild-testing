#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count and print from 0 to num
int count(int num) 
{
    printf("["); // Start of output sequence

    int i;
    // Loop over range 0 to num
    for(i = 0; i < num; i++)
    {
        // Add newline and comma for readability if num > 20
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        else 
        {
            // For smaller ranges, print all on same line
            printf("%d", i);
        }

        // Close the output sequence at end of range
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

// Driver function
int main()
{
    int num;

    // Prompt user for number
    printf("Count:~$ ");
    scanf("%d", &num);

    // Call function with user input
    count(num);
}
