/* c/algorithms/count.c */

/* Includes standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function that prints numbers from 0 to num */
int count(int num) 
{
    printf("[");
    
    /* Variable for the loop */
    int i;
    
    /* Loop to print numbers from 0 to num */
    for(i = 0; i < num; i++)
    {
        /* Prints each number with different format based on the value of num */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        else 
        {
            printf("%d", i);
        }
        
        /* Prints closing bracket when it reaches the last number */
        if(i == num - 1)
        {
            printf("]");
        }
    }
    /* Ends the function by returning 0 */
    return 0;
}

/* Main function */
int main()
{
    /* Variable to take user input */
    int num;

    /* Takes user input */
    printf("Count:~$ ");
    scanf("%d", &num);

    /* Call to count function */
    count(num);

    /* Ends the main function */
    return 0;
}
