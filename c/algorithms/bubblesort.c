#include <stdio.h>
#include <assert.h>

void bubble_sort(int *array, int len);

int main(void) 
{
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int expected[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};

    bubble_sort(yarr, 10);

    for (int i = 0; i < 10; i++)
        assert(yarr[i] == expected[i]);
    
    return 0;
}