/* Filename: c/algorithms/bubblesort.c 
 * Purpose: Program to perform bubble sort
 */

#include <stdio.h>

/* bubble_sort: function that sorts an array using bubble sort method */
void bubble_sort(int *array, int len) 
{
    /* Initial loop to iterate over array */
    for (int i = 0; i < len; i++) {
        /* Inner loop to perform swapping operation */
        for (int j = 0; j < len - i - 1; j++) {
            /* Check if current element is greater than next element */
            if (array[j] > array[j + 1]) {
                /* Swap operation if current element is greater than next element */
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main(void) 
{
    /* Create and initialise array */
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    /* Perform bubble sort on array */
    bubble_sort(yarr, 10);

    /* Print out sorted array */
    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);    
    printf("\b\b]\n");
    
    return 0;
}
