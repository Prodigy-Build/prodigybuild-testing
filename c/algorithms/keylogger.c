#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Added for strlen function

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]); // Changed to divide the size by size of the element
    int left = mid / 2; // Removed unnecessary calculations
    int right = mid - left;
    extern int i;
    
    if(element == mid)
        printf("%d", mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // Added check for sufficient arguments
    if(argc < 3)
    {
        printf("Insufficient arguments!\n");
        return 1;
    }
    
    int yarr[10];
    for(int i = 0; i < 10; i++)
    {
        yarr[i] = atoi(argv[i+1]); // Changed to convert command-line arguments to integers
    }
    
    binsearch(yarr, atoi(argv[11]));
    
    return 0;
}