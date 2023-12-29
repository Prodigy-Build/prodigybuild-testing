#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;                 // Added missing calculation for mid
    int left = mid;                                               // Corrected calculation for left
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;               // Corrected calculation for right
    extern int i;
    
    if(element == yarr[mid])                                      // Corrected comparison condition for mid
    printf("%d", yarr[mid]);                                      // Removed & from the printf statement
    
    if(element != yarr[right])
    {
        for(i = 0; i <= left; i++)                                 // Changed < to <= in for loop condition
        {
            if(element == yarr[i])                                 // Corrected comparison condition for i
            {
                //Does this so that it doesn't print multiple times
                printf("%d", yarr[i]);                              // Removed & from the printf statement
            }
        }
    }
}

int main(int argc, int argv[])
{
    binsearch(argv, argc);                                         // Corrected arguments passed to binsearch
}