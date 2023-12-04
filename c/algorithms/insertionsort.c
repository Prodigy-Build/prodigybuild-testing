#include <stdio.h>

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5];

    for (int i = 0; i < 5; i++)
    {
        sorted[i] = unsorted[i];
        for (int j = i; j > 0 && sorted[j] < sorted[j-1]; j--)
        {
            int temp = sorted[j];
            sorted[j] = sorted[j-1];
            sorted[j-1] = temp;
        }
    }

    return 0;
}