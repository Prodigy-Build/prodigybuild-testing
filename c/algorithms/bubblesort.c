// Adding comments and formatting the file "c/algorithms/bubblesort.c"
  
#include <stdio.h> //include standard input output library 

// Function to perform bubble sort
void bubble_sort(int *array, int len) 
{
    // Traversing through all array elements 
    for (int i = 0; i < len; i++) {
        // Traversing the array from 0 to array length - i - 1
        for (int j = 0; j < len - i - 1; j++) {
            // If current element is greater than the next
            if (array[j] > array[j + 1]) {
                // Swap the elements
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

// Main function
int main(void) 
{
    // Initialize array
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    // Call the bubble sort function
    bubble_sort(yarr, 10);

    // Print the sorted array
    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    
    // Return from the main function
    return 0;
}