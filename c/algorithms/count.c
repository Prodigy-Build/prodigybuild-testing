/* c/algorithms/count.c */

/* Include standard input/output library */
#include <stdio.h>

/* Include standard library */
#include <stdlib.h>

/* Include library for character type functions */
#include <ctype.h>

/* Function to count and print from 0 to given number */
int count(int num) 
{
    /* Start of array */
    printf("[");

    /* Counter variable */
    int i;
    
    /* Print all numbers from 0 to num */
    for(i = 0; i < num; i++)
    {
        /* If num is greater than 20, print each number on new line */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        /* Else print numbers on same line */
        else 
        {
            printf("%d, ", i);
        }

        /* Close array bracket at end of count */
        if(i == num - 1)
        {
            printf("]\n");
        }
    }

    /* Return successful execution */
    return 0;
}

/* Main function of the program */
int main()
{
    /* Variable to store user input */
    int num;

    /* Prompt user for input */
    printf("Count:~$ ");
    scanf("%d", &num);

    /* Call count function with user input */
    count(num);

    /* Return successful execution */
    return 0;
}
