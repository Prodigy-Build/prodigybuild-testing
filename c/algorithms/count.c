#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to count from 0 to num */
int count(int num) 
{
    printf("["); // Start of output array
    
    int i;
    for(i = 0; i < num; i++) // Iterating from 0 to num
    {
        /* Check if number is greater than 20 */
        if(num > 20)
        {
            /* Print number with a new line if num is greater than 20 */
            printf("\n%d, \n", i);
        }
        else 
        {
            /* Prints the number without a new line */
            printf("%d", i);
        }
        
        /* Check if the current number is the last in the sequence */
        if(i == num - 1)
        {
            printf("]"); // End of the output array
        }
    }
}

int main()
{
    int num;
    printf("Count:~$ "); // Prompt for user input
    scanf("%d", &num); // Read user input
    count(num); // Call count function with user's input

    return 0; // Return 0 if program runs successfully
}
