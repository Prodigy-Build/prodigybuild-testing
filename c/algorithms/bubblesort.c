```
#include <stdio.h>
#include <assert.h>

void bubble_sort(int *array, int len);

void test_bubble_sort() {
    int test1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(test1, 10);
    assert(test1[0] == 0);
    assert(test1[1] == 1);
    assert(test1[2] == 2);
    assert(test1[3] == 3);
    assert(test1[4] == 4);
    assert(test1[5] == 6);
    assert(test1[6] == 7);
    assert(test1[7] == 8);
    assert(test1[8] == 9);
    assert(test1[9] == 10);

    int test2[] = {5, 4, 3, 2, 1};
    bubble_sort(test2, 5);
    assert(test2[0] == 1);
    assert(test2[1] == 2);
    assert(test2[2] == 3);
    assert(test2[3] == 4);
    assert(test2[4] == 5);
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
```