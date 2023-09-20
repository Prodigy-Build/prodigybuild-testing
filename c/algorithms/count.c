/* File: c/algorithms/count.c */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * This function prints a sequence of integers from 0 to the given number.
 * If the number is greater than 20, each number is printed on a new line.
 * The sequence is enclosed within square brackets.
 * For example, the output for number 3 would be [0, 1, 2].
*/
int count(int num) 
{
    printf("[");
    int i;
    for(i = 0; i < num; i++)
    {
        if(num > 20)
        {
            printf("\n%d, \n", i);
        }
        else 
        {
            printf("%d", i);
        }
        
        if(i == num - 1)
        {
            printf("]");
        }
    }
}

/* 
 * This is the main function that drives the program.
 * It prompts the user to input a number, 
 * and then calls the count function with that number.
*/
int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    return 0;
}
/* End of file: c/algorithms/count.c */

