#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int left = 0;
    int right = 9;
    int mid;
    
    while(left <= right)
    {
        mid = (left + right) / 2;
        
        if(yarr[mid] == element)
        {
            return mid;
        }
        else if(yarr[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
    int yarr[10];
    int i;
    
    for(i = 1; i < argc; i++)
    {
        yarr[i - 1] = atoi(argv[i]);
    }
    
    int element = atoi(argv[argc - 1]);
    
    int result = binsearch(yarr, element);
    
    printf("%d", result);
    
    return 0;
}