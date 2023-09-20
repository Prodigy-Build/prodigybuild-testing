/* Includes standard input/output library functions */
#include <stdio.h>
/* Includes standard library functions */
#include <stdlib.h>
/* Includes character handling library functions */
#include <ctype.h>

/* Function to count numbers from 0 to the specified input */
int count(int num) 
{
    /* Print opening bracket for the output */
    printf("[");

    /* Loop to iterate from 0 to the input number */
    int i;
    for(i = 0; i < num; i++)
    {
        /* Print number with newline if input is greater than 20 */
        if(num > 20)
        {
            printf("\n%d, ", i);
        }
        /* Print number without newline if input is less than or equal to 20 */
        else 
        {
            printf("%d, ", i);
        }
        
        /* Print closing bracket at the end of numbers */
        if(i == num - 1)
        {
            printf("\b\b]"); /* Backspace to remove trailing comma */
        }
    }

    return 0;
}

/* Entry point of the program */
int main()
{
    /* Variable to hold the input number */
    int num;

    /* Output to ask user for input */
    printf("Enter a number: ");

    /* Get user input */
    scanf("%d", &num);

    /* Call count function with user input */
    count(num);

    return 0;
}

