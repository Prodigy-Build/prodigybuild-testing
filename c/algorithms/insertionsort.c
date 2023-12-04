#include <stdio.h>

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5];
    int n = sizeof(unsorted) / sizeof(unsorted[0]);

    for (int i = 0; i < n; i++)
    {
        int key = unsorted[i];
        int j = i - 1;

        while (j >= 0 && unsorted[j] > key)
        {
            unsorted[j + 1] = unsorted[j];
            j = j - 1;
        }
        unsorted[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
    {
        sorted[i] = unsorted[i];
    }

    return 0;
}