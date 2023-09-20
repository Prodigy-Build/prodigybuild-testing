/* Inclusion of necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function count definition */
int count(int num) 
{
    /* Print the starting bracket */
    printf("[");

    /* Loop through 0 to num */
    int i;
    for(i = 0; i < num; i++)
    {
        /* Print each number on a new line if num > 20 */
        if(num > 20)
        {
            printf("\n%d, ", i);
        }
        /* Otherwise print on the same line */
        else 
        {
            printf("%d, ", i);
        }
        
        /* Close bracket after last number */
        if(i == num - 1)
        {
            printf("]\n");
        }
    }
}

/* Main function definition */
int main()
{
    /* Declaration of input variable */
    int num;
    
    /* Asking for inputs */
    printf("Count:~$ ");
    scanf("%d", &num);
    
    /* Calling count function */
    count(num);

    /* Exit with no error */
    return 0;
}
