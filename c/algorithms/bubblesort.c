#include <stdio.h>

void bubble_sort(int *array, int len) 
{
    int i, j, tmp;

    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main(void) 
{
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int len = sizeof(yarr) / sizeof(yarr[0]);

    bubble_sort(yarr, len);

    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d, ", yarr[i]);	
    }
    printf("\b\b]\n");
    return 0;
}