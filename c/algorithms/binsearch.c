#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    extern int i;
    
    if(element == yarr[mid])
    printf("%d", element);
    
    if(element != yarr[right])
    {
        for(i = 0; i <= left; i++)
        {
            if(element == yarr[i])
            {
            printf("%d", element);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    binsearch(yarr, 5);
}