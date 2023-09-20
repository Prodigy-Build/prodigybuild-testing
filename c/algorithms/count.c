```c
/* Including necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to print numbers from 0 to given input 'num' */
int count(int num) 
{
    // Start of array
    printf("[");

    int i;
    // Loop that counts till 'num'
    for(i = 0; i < num; i++)
    {
        // If 'num' is greater than 20 
        // Printing the numbers in newline
        if(num > 20)
        {
            printf("%d, \n", i);
        }
        // If 'num' is less than or equals to 20 
        // Printing the numbers in same line
        else 
        {
            printf("%d", i);
        }
        // if it is the last count, closing the array bracket
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

int main()
{
    int num;

    // Prompt for input
    printf("Count:~$ ");

    // Scanning the user input
    scanf("%d", &num);

    // Calling the 'count' function
    count(num);
}
