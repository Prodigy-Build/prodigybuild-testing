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

void test_bubble_sort() {
    int test1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(test1, 10);
    int result1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        assert(test1[i] == result1[i]);
    }
    
    int test2[] = {5, 4, 3, 2, 1};
    bubble_sort(test2, 5);
    int result2[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        assert(test2[i] == result2[i]);
    }
    
    int test3[] = {1, 2, 3, 4, 5};
    bubble_sort(test3, 5);
    int result3[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        assert(test3[i] == result3[i]);
    }
}

int main(void) 
{
    test_bubble_sort();
    
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}