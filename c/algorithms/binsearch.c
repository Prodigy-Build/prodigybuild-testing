#include <stdio.h>

int binsearch(int yarr[], int n, int element)
{
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if(yarr[mid] == element) 
        {
            return mid;
        }
      
        if(yarr[mid] < element) 
        {
            left = mid + 1;
        } 
        else
        {
            right = mid - 1;
        }
    }
    
    return -1;
};

int main(int argc, char *argv[])
{
    int yarr[10] = {1, 3, 4, 6, 7, 8, 10, 13, 14, 17};
    int element = atoi(argv[1]);
    int result = binsearch(yarr, 10, element);

    if (result != -1)
        printf("Element is found at index %d", result);
    else
        printf("Element is not found in array");
  
    return 0;
}