#include <stdio.h>

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5];
    int size = sizeof(unsorted) / sizeof(unsorted[0]);

    for (int i = 0; i < size; i++)
    {
        sorted[i] = unsorted[i];
    }

    for (int i = 1; i < size; i++)
    {
        int key = sorted[i];
        int j = i - 1;

        while (j >= 0 && sorted[j] > key)
        {
            sorted[j + 1] = sorted[j];
            j--;
        }
        
        sorted[j + 1] = key;
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sorted[i]);
    }
    
    return 0;
}