#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int count(int num);
void test_count();

int main()
{
    test_count();
    return 0;
}

// Function to count numbers and print them in square brackets
int count(int num)
{
    printf("[");
    
    if (num > 20)
    {
        for (int i = 0; i < num; i++)
        {
            printf("\n%d, \n", i);
        }
            
        if (num > 0)
        {
            printf("%d, ", num);
        }
    } 
    else
    {
        for (int i = 0; i < num; i++)
        {
            printf("%d, ", i);
        }
    }
    
    printf("]");
}

void test_count()
{
    // Test count function
    count(10);  // Expected output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ]
    count(25);  // Expected output: [0, 
                //                      1, 
                //                      2, 
                //                      3, 
                //                      4, 
                //                      5, 
                //                      6, 
                //                      7, 
                //                      8, 
                //                      9, 
                //                      10, 
                //                      11, 
                //                      12, 
                //                      13, 
                //                      14, 
                //                      15, 
                //                      16, 
                //                      17, 
                //                      18, 
                //                      19, 
                //                      20, 
                //                      21, 
                //                      22, 
                //                      23, 
                //                      24, 
                //                      25, ]
    count(0);   // Expected output: []
}