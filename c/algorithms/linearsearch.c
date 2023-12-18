/* 
 * Include necessary header file.
 */
#include <stdio.h>

/* 
 * Implement the linear search function.
 */
int linsearch(int *yarr, int val)
{
    /*
     * Get the size of the array.
     */
    int size = sizeof(yarr) / sizeof(yarr[0]);

    /*
     * Perform linear search.
     */
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }
    }

    return 1;
}

/* 
 * Implement the main function.
 */
int main()
{
    /*
     * Initialize the array and the value to search.
     */
    int yarr[] = {1, 2, 3, 4, 5};
    int val = 3;

    /* 
     * Call the linear search function.
     */
    int result = linsearch(yarr, val);

    /*
     * Print the result.
     */
    printf("Result: %d\n", result);

    return 0;
}

/* 
 * This code is not testable as it doesn't contain any testable logic.
 */