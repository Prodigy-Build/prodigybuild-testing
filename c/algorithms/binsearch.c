#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int length = sizeof(yarr) / sizeof(yarr[0]);
    int left = 0;
    int right = length - 1;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (yarr[mid] == element) {
            return mid;
        }
        else if (element < yarr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return -1; // Element not found
}

int main(int argc, char *argv[])
{
    int yarr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int element = atoi(argv[1]);
    
    int result = binsearch(yarr, element);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", element, result);
    }
    else {
        printf("Element not found\n");
    }
    
    return 0;
}