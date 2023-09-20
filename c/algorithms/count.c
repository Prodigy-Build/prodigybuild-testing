/* Updated 'count.c' file */

#include <stdio.h>  /* Standard input/output */
#include <stdlib.h> /* Standard General utilities Library */
#include <ctype.h>  /* Character handling functions */

/* Function to count numbers from 0 to input number */
int count(int num) 
{
    printf("[");  /* Start of list */
    
    for(int i = 0; i < num; i++)  /* Loops from 0 to input number */
    {
        /* Separate new lines if number is greater than 20 */
        if(num > 20)
        {
            printf("\n%d, \n", i);  
        }
        else 
        {
            printf("%d", i);  /* Prints number */
        }
        
        /* Adds closing bracket for end of list */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

int main()
{
    int num;  /* Variable to hold user input */
    
    printf("Count:~$ ");  
    scanf("%d", &num);  /* Scans user input */

    count(num);  /* Calls function with user input as argument */
}

/* End of the 'count.c' file */

