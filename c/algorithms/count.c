#include <stdio.h>  /* Standard Input/Output header file */
#include <stdlib.h> /* Standard Library header file */
#include <ctype.h>  /* Character type header file */

/* Function to count numbers up to the input value */
int count(int num) 
{
    printf("[");  /* Start printing the array */
    
    int i;
    for(i = 0; i < num; i++)  /* Iterate from 0 up to the input number */
    {
        if(num > 20)
        {
            printf("\n%d, \n", i);  /* Print each number with a newline if the input number is more than 20 */
        }
        else 
        {
            printf("%d", i);  /* Print each number without a newline for numbers less than or equal to 20 */
        }
        
        if(i == num - 1)
        {
            printf("]");  /* Print the closing bracket for the array */
        }
    }
}

/* Main function */
int main()
{
    int num;  /* Declare a variable to hold the number to be counted */
    printf("Count:~$ ");  /* Ask the user for input */
    scanf("%d", &num);  /* Store the user input in num variable */
    count(num);  /* Call the count function and pass num as the argument */
}

