#include <stdio.h>
#include <stdlib.h>

/*
 * This code generates the Fibonacci sequence using a for loop.
 * 
 * The variables 'a' and 'b' represent the two previous numbers in the sequence.
 * In each iteration of the loop, 'a' is incremented by 1 and 'b' is incremented by 1.
 * The loop will continue as long as 'b' is greater than 'a'.
 * 
 * Inside the loop, the current values of 'a' and 'b' are printed using printf.
 * 
 * After the loop, there is an if statement that checks if 'b' is equal to the size of a long integer.
 * If it is, the program exits with a status of 1.
 */

int main()
{
    long a;
    long b;
    
    for(a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld", a, b);
    }
    
    if(b == sizeof(long))
    {
        exit(1);
    }
}