#include <stdio.h>

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5];
    int i, j, temp, n;

    n = sizeof(unsorted) / sizeof(unsorted[0]);

    for(i = 1; i < n; i++)
    {
        j = i - 1;
        temp = unsorted[i];

        while(j >= 0 && temp < unsorted[j])
        {
            unsorted[j + 1] = unsorted[j];
            j--;
        }

        unsorted[j + 1] = temp;
    }

    for(i = 0; i < n; i++)
    {
        sorted[i] = unsorted[i];
    }

    return 0;
}