#include <stdio.h>

void bubble_sort(int *array, int len) {
    int i, j, temp;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}