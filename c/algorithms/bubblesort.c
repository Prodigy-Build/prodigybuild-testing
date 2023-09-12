#include <stdio.h>
#include <assert.h>

void bubble_sort(int *array, int len) 
{
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void unit_test(void)
{
    int a[6] = {2, 7, 4, 1, 5, 3};
    int sorted_a[6] = {1, 2, 3, 4, 5, 7};
    bubble_sort(a, 6);
    for (int i = 0; i < 6; i++)
        assert(a[i] == sorted_a[i]);

    int b[6] = {9, 8, 7, 6, 5, 2};
    int sorted_b[6] = {2, 5, 6, 7, 8, 9};
    bubble_sort(b, 6);
    for (int i = 0; i < 6; i++)
        assert(b[i] == sorted_b[i]);

    printf("All test cases passed.\n");
}

int main(void) 
{
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};

    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");

    unit_test();

    return 0;
}