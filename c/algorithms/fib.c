```c
#include <stdio.h>
#include <stdlib.h> // Add this include to use exit() function

// Declare the binsearch function
int binsearch(int yarr[10], int element)
{
    // Fix the equation for calculating the mid, left, and right values
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2; // Divide sizeof(yarr) by sizeof(yarr[0]) to get the array size
    int left = mid; // Assign mid to left directly, no need to subtract mid here
    int right = sizeof(yarr) / sizeof(yarr[0]) - left; // Subtract left from the array size to get right
    
    extern int i;

    if (element == yarr[mid]) // Fix the condition to compare element with yarr[mid]
    {
        printf("%d\n", yarr[mid]); // Print yarr[mid] instead of &mid
    }
    
    if (element != yarr[right])
    {
        for (i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                // Print yarr[i] instead of &i
                printf("%d\n", yarr[i]);
            }
        }
    }
}

// Declare the main function with correct signature
int main(int argc, char *argv[]) // Change int argv[] to char *argv[]
{
    // Convert command-line arguments to integers and pass them to binsearch function
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = atoi(argv[1]); // Convert the second argument to integer

    binsearch(yarr, element);
    
    return 0; // Add return statement to main function
}
```