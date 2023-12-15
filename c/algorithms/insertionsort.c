#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]);

    if(element == yarr[mid])
    {
      printf("%d", mid);
    }
    
    if(element != yarr[right])
    {
        for(int i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5];
    int a = 0;
    
    do
    {
        a++;
        int b = a + 1;
        
        if(unsorted[a] < unsorted[b])
        {
            sorted[a] = unsorted[a];
        }
    } while(sizeof(sorted) / sizeof(sorted[0]) != sizeof(unsorted) / sizeof(unsorted[0]));
    
    return 0;
}