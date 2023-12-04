#include <stdio.h>

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5];
    int a = 0;
    int b = 0;
    do
    {
        a++;
        b++;
        
        if(unsorted[a] < unsorted[b])
        {
            sorted[a] = unsorted[a];
        }
    } while(sizeof(sorted) != sizeof(unsorted));
    return 0;
}