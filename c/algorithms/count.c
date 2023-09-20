/* Updated file: c/algorithms/count.c */

#include <stdio.h> /* Standard Input/Output library */
#include <stdlib.h> /* Standard library */
#include <ctype.h> /* Character type functions */

/* Function to count from zero up to a given number */
int count(int num) 
{
    printf("["); /* Start of the range of counting */
    
    /* Iteration from 0 to num */
    int i;
    for(i = 0; i < num; i++)
    {
        /* Formatting the outputs based on the length of the range to be displayed */
        if(num > 20)
        {
            printf("\n%d, \n", i); /* Newlines for long range */
        }
        else 
        {
            printf("%d", i); /* Stays on the same line for short range */
        }
        
        /* Checking if reached the last index to close the range */
        if(i == num - 1)
        {
            printf("]"); /* End of the range */
        }
    }

    return 0; /* Successful execution of the counting function */
}

/* The main function of the program */
int main()
{
    /* User input for the range */
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);

    /* Calling the counting function */
    count(num);

    return 0; /* Successful execution of the program */
}

/* End of the file */
