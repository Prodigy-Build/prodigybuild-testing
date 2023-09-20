/* Imported libraries */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to print count from 0 to a given number */
int count(int num) 
{
    printf("[");   // Opening bracket for the list
    
    // Loop to print each number till the given num
    int i;
    for(i = 0; i < num; i++)
    {
        // If num is greater than 20, print the number on new line
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        else  // If num is less than 20, print the number on same line
        {
            printf("%d", i);
        }
        
        // Print closing bracket for the list at the end of the line
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
    printf("Count:~$ ");  // Prompt user for an input
    scanf("%d", &num);    // Read user input
    count(num);           // Call count function

    return 0;             // End of function
}