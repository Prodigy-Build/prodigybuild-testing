#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_index])
            min_index = j;
        swap(&arr[min_index], &arr[i]);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: ./your-executable-name [array size] [array]\n");
        printf("Example: ./your-executable-name 3 2 1 0\n");
        return EXIT_FAILURE;
    }

    int size = atoi(argv[1]);
    if(!size) {
        printf("Error: size of array can't be 0\n");
        return EXIT_FAILURE;
    }

    int arr[size];
    for(int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i+2]); 
    }

    printf("Before sorting: ");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("After sorting:  ");
    printArray(arr, size);

    return EXIT_SUCCESS;
}