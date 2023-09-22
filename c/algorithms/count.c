```c
/* Include the necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to count from 0 to given number */
int count(int num) 
{
    /* Start the output with an opening bracket */
    printf("[");

    /* Declare variable for loop counter */
    int i;

    /* Loop from 0 to given number (non-inclusive) */
    for(i = 0; i < num; i++)
    {
        /* If the given number is greater than 20, print each number on a new line with trailing comma */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        /* If the given number is 20 or less, print each number on the same line without a trailing comma */
        else 
        {
            printf("%d", i);
        }

        /* If the current number is the last in the sequence, print a closing bracket */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

/* Main function to gather input and call count function */
int main()
{
    /* Declare variable for input */
    int num;

    /* Prompt for input */
    printf("Count:~$ ");
    
    /* Store user input in num variable */
    scanf("%d", &num);

    /* Call count function with user input */
    count(num);
}
```