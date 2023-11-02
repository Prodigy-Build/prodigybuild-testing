#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int left = 0;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    int mid = (left + right) / 2;
    
    if(element == yarr[mid])
    {
        printf("%d\n", mid);
        return;
    }
    
    while(left <= right)
    {
        if(element < yarr[mid])
            right = mid - 1;
        else
            left = mid + 1;
        
        mid = (left + right) / 2;
        
        if(element == yarr[mid])
        {
            printf("%d\n", mid);
            return;
        }
        
        if(element == yarr[left])
        {
            printf("%d\n", left);
            return;
        }
        
        if(element == yarr[right])
        {
            printf("%d\n", right);
            return;
        }
    }
    
    printf("-1\n");
}

int main(int argc, char *argv[])
{
    int yarr[] = {2, 5, 7, 10, 15, 20};
    int element = 15;
    
    binsearch(yarr, element);
    
    return 0;
}