/* FILE: c/algorithms/count.c */

/* Import necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to count from 0 to given number */
int count(int num) 
{
    printf("[");  // Start of output array
    
    int i;
    /* Loop through all integers from 0 to num */
    for(i = 0; i < num; i++)
    {
        /* If num is greater than 20, print each integer on a new line */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        /* Otherwise, print integers on the same line */
        else 
        {
            printf("%d", i);
        }
        
        /* If this is the last integer, end the output array */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

int main()
{
    /* Declare variable to hold input number */
    int num;
    /* Prompt user for input number */
    printf("Count:~$ ");
    scanf("%d", &num);
    /* Call count function with input number */
    count(num);
}
