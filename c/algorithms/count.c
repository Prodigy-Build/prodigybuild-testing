#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Standard library functions */
#include <ctype.h> /* Character type functions */

/*
* Function to count from 0 to num - 1 and print
* the result in a format
* Input: num - the number to count up to
*/
int count(int num) 
{
    printf("["); /* Starting point */
    
    int i; /* Counter */
    for(i = 0; i < num; i++)
    {
        if(num > 20) /* Handling for limit > 20 */
        {
            printf("\n%d, \n", i); /* Print number and comma in new line */
        }
        else 
        {
            printf("%d", i); /* Otherwise just print number */
        }
        
        if(i == num - 1) /* If last number */
        {
            printf("]"); /* End bracket for last number */
        }
    }
}

/*
* Main function to take user input and initiate count
*/
int main()
{
    int num; /* User input number */
    printf("Count:~$ "); /* Prompt for input */
    scanf("%d", &num); /* Read user input */
    count(num); /* Initiate counting */
}

