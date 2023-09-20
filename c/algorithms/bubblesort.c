#include <stdio.h>  // include the standard input/output library

// Function to perform bubble sort on a given array
void bubble_sort(int *array, int len) 
{
    // outer loop iterating through each element
    for (int i = 0; i < len; i++) {
        // inner loop to compare adjacent elements
        for (int j = 0; j < len - i - 1; j++) {
            // Swap if current element is greater than next
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

// The program starts here
int main(void) 
{
    // Define and initialize the array
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    // Perform bubble sort on the array
    bubble_sort(yarr, 10);

    // Print the sorted array
    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}
