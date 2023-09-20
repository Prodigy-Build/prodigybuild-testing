/* updated c/algorithms/count.c file */

#include <stdio.h>   /* needed for console I/O */
#include <stdlib.h>  /* standard library */
#include <ctype.h>   /* includes tolower(), toaggle() etc. */

// function definition of count
int count(int num) 
{
    printf("[");
    
    int i;
    
    // using for loop to count till number passed in argument
    for(i = 0; i < num; i++)
    {
        // if number is greater than 20, then print in newline
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        // for numbers less than or equal to 20, print in same line
        else 
        {
            printf("%d", i);
        }
        
        // when it's last iteration print closing bracket
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

// main function
int main()
{
    int num;
    printf("Count:~$ ");
    // taking number input
    scanf("%d", &num);
    // invoking count function
    count(num);
}

