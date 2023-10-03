#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[10], int element)
{
    int start = 0, end = 9;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        if (yarr[mid] == element) {
            return mid;
        } else if (yarr[mid] < element) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return -1;
}

int main(int argc, char* argv[])
{
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = atoi(argv[1]);
    
    int index = binsearch(yarr, element);
    
    if (index != -1) {
        printf("Element found at index: %d", index);
    } else {
        printf("Element not found");
    }
    
    return 0;
}