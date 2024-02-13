#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (yarr[mid] == element) {
            return mid;
        }
        if (yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
};

int main(int argc, char *argv[])
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Example array for binary search
    int element = atoi(argv[1]);
    int position = binsearch(array, sizeof array / sizeof array[0], element);
    
    if (position != -1){
        printf("Element found at index %d", position);
    }
    else{
        printf("Element not found in the array");
    }
    
    return 0;
}