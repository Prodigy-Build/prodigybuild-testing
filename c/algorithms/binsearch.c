#include <stdio.h>

int binsearch(int yarr[], int n, int element)
{
    int left = 0;
    int right = n - 1;
    int mid;
    
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        
        if(yarr[mid] == element)
        {
            //Print the index if element is found
            printf("%d", mid);
            return mid;
        }
        
        if(yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    // If element is not present, return -1
    return -1;
};

int main(int argc, char *argv[])
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int element = atoi(argv[1]);
    binsearch(arr, 10, element);
    return 0;
}