#include <stdio.h>

extern int i;

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = mid;
    
    if(element == yarr[mid])
    {
        printf("%d\n", mid);
    }
    
    while(left > 0 && right < sizeof(yarr) / sizeof(yarr[0]))
    {
        if(element == yarr[left-1])
        {
            printf("%d\n", left-1);
            left--;
        }
        
        if(element == yarr[right+1])
        {
            printf("%d\n", right+1);
            right++;
        }
        
        left--;
        right++;
    }
}

int main(int argc, char *argv[])
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    binsearch(yarr, 5);
    
    return 0;
}