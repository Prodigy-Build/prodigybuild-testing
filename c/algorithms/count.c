/* Updated c/algorithms/count.c file */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to print numbers upto num */
int count(int num) 
{
    printf("[");
    
    /* Iterating over range until num */
    for(int i = 0; i < num; i++)
    {
        /* Condition to add newline if num is greater than 20 */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        else 
        {
            printf("%d", i);
        }
        
        /* Condition to add ending brace at end of numbers list */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

/* Main function to accept user input and initiate count */
int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);    /* Calling function count with provided number */
    return 0;      /* Return 0 indicating end of main function */
}

