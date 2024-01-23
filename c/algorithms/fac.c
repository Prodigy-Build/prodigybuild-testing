#include <stdio.h>
#include <stdlib.h>

// Factorial Function
int fac(int n) {
    if(n < 0) {
        exit(-1); // terminate with an error 
    }
    else if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * fac(n - 1);
    }
}

// Binary Search Function
int binsearch(int array[], int array_size, int element){
    int left = 0;
    int right = array_size - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        // If element is present at middle 
        if (array[mid] == element) {
            return mid;
        }

        // If element is greater, ignore left half 
        if (array[mid] < element) {
            left = mid + 1;
        }

        // If element is smaller, ignore right half 
        else {
            right = mid - 1;
        }
    }

    // if we reach here, then the element was not present 
    return -1; 
}

int main(int argc, char *argv[]) {
    int arr[5] = {1,2,3,4,5};
    
    //Call the binsearch function
    int res = binsearch(arr, 5, atoi(argv[1]));
    (res != -1)? printf("Element is present at index %d\n", res)
               : printf("Element is not present in array\n");
    
    //Call the fac function
    printf("Factorial of %d: %d\n", atoi(argv[1]), fac(atoi(argv[1])));
    return 0;
}