// count.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to print numbers till 'num'
void count(int num) 
{
    printf("["); // Start symbol
    
    // Looping from 0 to num
    for(int i = 0; i < num; i++)
    {
        // Print with newline if num > 20
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        // Else print on the same line
        else 
        {
            printf("%d", i);
        }
        
        // End symbol
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

int main()
{
    int num;

    // Taking user input
    printf("Count:~$ ");
    scanf("%d", &num);

    // Calling function with the input
    count(num);

    return 0; // Program exited without errors
}
