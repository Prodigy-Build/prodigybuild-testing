#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = sizeof(yarr) - left;
    extern int i;
    
    if(element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                // Does this so that it doesn't print multiple times
                printf("%d", yarr[i]);
            }
        }
    }
    
    return 0;
}

int main(int argc, char* argv[])
{
    int testArray[10] = {1, 5, 7, 12, 18, 21, 25, 27, 30, 33};
    int element = 18;
    
    binsearch(testArray, element);
    
    return 0;
}