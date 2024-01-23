#include <stdio.h>

int binsearch(int arr[], int size, int element){
    int start = 0;
    int end = size-1;
    
    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == element){
            return mid;  
        }

        if(arr[mid] < element){
            start = mid + 1;  
        } else {
            end = mid - 1;
        }
    }

    return -1; 
}

int main(int argc, char *argv[]){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int element = atoi(argv[1]);
    int position = binsearch(arr, 10, element);
    if (position != -1){
        printf("The element is found at position %d\n", position);
    }else{
        printf("Element not found\n");
    }
    return 0;
}