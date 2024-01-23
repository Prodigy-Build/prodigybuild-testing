#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num)
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        if(i == num + 1)
            printf("]");
    } else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
}

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = sizeof(yarr) - left;
    extern int i;
    
    if(element == mid)
        printf("%d", mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int main(int argc, int *argv[])
{
    binsearch(argv[0], argv[1]);
}