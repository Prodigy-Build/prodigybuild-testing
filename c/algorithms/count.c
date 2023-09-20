#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to print numbers up to given number */
int count(int num) 
{
    printf("[");                                              // Start of array

    for(int i = 0; i < num; i++)                               // Loop to print numbers
    {
        if(num > 20)
        {
            printf("\n%d, \n", i);                             // New line for every number if num is greater than 20
        }
        else 
        {
            printf("%d", i);                                   // Same line for every number if num is less or equal to 20
        }
        
        if(i == num - 1)
        {
            printf("]");                                       // End of array
        }
    }
}

int main()
{
    int num;
    printf("Count:~$ ");                                       // Prompt user to input
    scanf("%d", &num);                                         // Get user input
    count(num);                                                // Call function count
}

