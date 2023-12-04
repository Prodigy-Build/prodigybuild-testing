#include <stdio.h>

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5];
    int length = sizeof(unsorted) / sizeof(unsorted[0]);
    for (int i = 1; i < length; i++)
    {
        int current = unsorted[i];
        int j = i - 1;
        while (j >= 0 && unsorted[j] > current)
        {
            unsorted[j + 1] = unsorted[j];
            j--;
        }
        unsorted[j + 1] = current;
    }
    for (int i = 0; i < length; i++)
    {
        sorted[i] = unsorted[i];
    }
    return 0;
}