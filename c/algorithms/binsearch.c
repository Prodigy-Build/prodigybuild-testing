#include <stdio.h>

//Define Binary Search Function
int binsearch(int yarr[], int n, int element) 
{
    int left = 0, right = n - 1;
    
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
  
        if (yarr[mid] == element) 
        {
            printf("%d", yarr[mid]);
            return mid;
        }

        if (yarr[mid] < element) 
            left = mid + 1; 
        else
            right = mid - 1; 
    } 
  
    return -1; 
} 

int main(int argc, char *argv[]) {
    int yarr[] = {2, 3, 4, 10, 40};
    int n = sizeof(yarr) / sizeof(yarr[0]);
    int result = binsearch(yarr, n, atoi(argv[1]));

    if(result == -1) 
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
  
    return 0; 
}