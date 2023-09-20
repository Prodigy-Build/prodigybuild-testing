/* File c/algorithms/count.c */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
Function to count from 0 to the provided number and print the count
@param num: integer number to count to
*/
int count(int num) 
{
    /* Printing opening square bracket */
    printf("[");
    
    /* Declaring loop variable */
    int i;
    
    /* Looping through the num */
    for(i = 0; i < num; i++)
    {
        /* Formatting the print statements based on the input size */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        else 
        {
            printf("%d", i);
        }
        
        /* Print closing bracket at the end of count */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

int main()
{
    /* Declaring and reading the input number*/
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);

    /* Calling count function with the read input */
    count(num);

    /* Indicating successful program completion */
    return 0;
}
