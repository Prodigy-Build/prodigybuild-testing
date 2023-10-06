#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for using exit function

int main()
{
    // Declare variables
    long a;
    long b;
    
    // Loop to generate Fibonacci sequence
    for(a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld\n", a, b); // Remove '&' from printf statement
    }
    
    // Check validation and exit if required
    if(b >= sizeof(long))
    {
        exit(1);
    }
}