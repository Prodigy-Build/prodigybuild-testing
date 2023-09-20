#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to print numbers from 0 to num */
int count(int num) 
{
    /* Print the opening bracket of array */
    printf("[");

    /* Create an integer i for for loop */
    int i;

    /* Start of the for loop */
    for(i = 0; i < num; i++)
    {
        /* If the number is more than 20, print each number in new line */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        /* Else print the numbers in same line separated by comma */
        else 
        {
            printf("%d", i);
        }

        /* If i is the last number, print the closing bracket of array */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

/* Main function start */
int main()
{
    /* Create an integer num to hold user input */
    int num;

    /* Ask for user input */
    printf("Count:~$ ");
    scanf("%d", &num);

    /* Call count function with user input as argument */
    count(num);
    return 0; /* Return 0 if the program is successful */
} 
