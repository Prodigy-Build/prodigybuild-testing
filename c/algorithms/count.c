/* File: c/algorithms/count.c */

/* Including necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* 
Function to print numbers from 0 to num 
For numbers greater than 20, it prints each number in a new line
*/
int count(int num) 
{
    printf("["); // Start of array notation

    int i;
    for(i = 0; i < num; i++) // Loop through 0 to num
    {
        if(num > 20)
        {
            printf("\n%d, \n", i); // Print each number in new line if num > 20
        }
        else 
        {
            printf("%d", i); // Print in same line if num <= 20
        }

        /* Print the closing bracket for last number */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

/* Main function */
int main()
{
    int num;
    printf("Count:~$ "); // Prompt to enter the number
    scanf("%d", &num); // Reading the number
    count(num); // Calling the count function
}

/* End of File */

