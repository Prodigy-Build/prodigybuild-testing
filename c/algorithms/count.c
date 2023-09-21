```c
// Including necessary library files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* This function receives an integer input parameter num.
 * It prints each number from 0 to num-1 in individual lines if input num is greater than 20.
 * Else it just prints the numbers with no newline character.
 * The formatted print is enclosed within square brackets */
int count(int num) 
{
    // Each output will be enclosed within a square bracker, here we insert the opening bracket
    printf("[");

    // Iterating from 0 to num - 1
    for(int i = 0; i < num; i++)
    {
        // Checking if number is greater than 20. If yes, printing number in new line. If not, in the same line.
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        else 
        {
            printf("%d ", i);
        }
        
        // Closing bracket is printed after last number
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

// Main function
int main()
{
    int num;     // Variable for storing user input
    printf("Count:~$ ");  // Asking for user input
    scanf("%d", &num);    // Storing user input on variable num
    count(num);   // Calling function count with user given input
}
```