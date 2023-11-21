#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    extern int i;
    
    if (element == yarr[mid]) {
        printf("%d", mid);
    }
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (yarr[mid] == element) {
            printf("%d", mid);
            return mid;
        }
        
        if (yarr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main(int argc, char* argv[])
{
    int yarr[10];
    int element;
    
    // Populate the yarr array and assign element with the value to search
    
    binsearch(yarr, element);
    
    return 0;
}