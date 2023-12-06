#include <stdio.h>
#include <stdlib.h> // Added the necessary library for exit function

int main()
{
    long a = 0; // Initialize variable "a" to 0
    long b = 1; // Initialize variable "b" to 1
    
    for(; b > a; b++) // Removed the unnecessary initialization statement "a = 0" inside the for loop
    {
        a++;
        printf("%ld \n %ld\n", a, b); // Removed the "&" before the variables in the printf function
    }
    
    if(b == sizeof(long)) // Removed the unnecessary reference operator "&" before "b"
    {
        exit(1);
    }

    return 0; // Added a return statement
}