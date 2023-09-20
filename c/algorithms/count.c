/* File: c/algorithms/count.c */

/* Including necessary libraries */
#include <stdio.h>   /* Included for input and output functions */
#include <stdlib.h>  /* Included for system functions */
#include <ctype.h>   /* Included for character functions */

/* A function that displays numbers from 0 to num-1 */
int count(int num) 
{
    printf("[");
    
    /* Looping from 0 to num - 1 */
    for(int i = 0; i < num; i++)
    {
         /* If num is larger than 20, add new line for better visuals */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        /* If it’s less than or equal to 20, add numbers in a single line */
        else 
        {
            printf("%d", i);
        }
        
        /* Add a closing bracket at the end of the range of numbers */
        if(i == num - 1)
        {
            printf("]");
        }
     }
}

/* Main function of the program */
int main()
{
    /* Variable to hold user's number */
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    
    /* Call count function with user's number */
    count(num); 

    /* Exit the program */
    return 0;
}

/* End of the file */

