```C
/* File: c/algorithms/count.c */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Count function: This function takes an integer 'num' and prints all numbers up to it */
int count(int num) 
{
    printf("[");
    
    int i;
    /* Iterate from 0 to 'num' */
    for(i = 0; i < num; i++)
    {
        /* If 'num' is greater than 20, print each number on a new line for readability */
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        /* Else, print the number on the same line */
        else 
        {
            printf("%d", i);
        }
        
        /* If current number is the last one, print closing bracket */
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

/* Main function: This function asks user for a number and calls the count function */
int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}
```
