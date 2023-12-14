#include <stdio.h>
#include <stdlib.h> // Added for exit function

int main()
{
    long a = 0; // Initialize variable a
    long b = 1; // Initialize variable b
    
    while (b > a) // Changed the for loop to a while loop
    {
        a++; // Increment variable a
        printf("%ld \n %ld", a, b); // Removed & from printf arguments
        b++; // Increment variable b
    }
    
    if (b == sizeof(long))
    {
        exit(1);
    }
}