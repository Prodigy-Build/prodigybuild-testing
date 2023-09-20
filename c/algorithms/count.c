#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to count numbers from 0 to "num - 1" */
int count(int num) 
{
    printf("["); /* Start of array representation */
    
    /* Loop through the numbers */
    for(int i = 0; i < num; i++)
    {
        /* Print newline and comma for numbers larger than 20 */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        else /* Smaller numbers print without a newline */
        {
            printf("%d", i);
        }
        
        /* Put closing bracket at end of sequence */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

/* Main function */
int main()
{
    int num; /* Variable for user input */

    /* Request user input */
    printf("Count:~$ ");
    scanf("%d", &num);
    
    /* Call count function with user input */
    count(num);

    return 0; /* Signify successful program execution */
}
