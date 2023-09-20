/* File: c/algorithms/count.c */

/* Header files: stdio for input-output functions,
   stdlib for general utility functions,
   ctype for character test functions */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to count from 0 to num and print the numbers */
int count(int num) 
{
    /* Start of the number array */
    printf("[");

    /* Loop for counting */
    int i;
    for(i = 0; i < num; i++)
    {
        /* If num is more than 20, print each number on new line */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        /* If num is 20 or less, print numbers on same line */
        else 
        {
            printf("%d", i);
        }

        /* Add closing bracket at the end of array */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

/* Main function that accepts user input */
int main()
{
    /* Variable declaration */
    int num;

    /* Prompt user to enter a number */
    printf("Count:~$ ");
    scanf("%d", &num);

    /* Call the count function */
    count(num);
}

