#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = sizeof(yarr) - left;
    extern int i;
    
    if(element == yarr[mid])
        printf("%d\n", mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d\n", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    assert(binsearch(yarr, 5) == 4);
    assert(binsearch(yarr, 10) == 9);
    
    return 0;
}