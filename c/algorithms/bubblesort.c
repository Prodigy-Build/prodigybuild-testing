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

int main(void) 
{
    // Test case 1
    int yarr1[] = {5, 2, 6, 3, 1, 4};
    bubble_sort(yarr1, 6);
    assert(yarr1[0] == 1);
    assert(yarr1[1] == 2);
    assert(yarr1[2] == 3);
    assert(yarr1[3] == 4);
    assert(yarr1[4] == 5);
    assert(yarr1[5] == 6);
    
    // Test case 2
    int yarr2[] = {9, 5, 7, 2, 8, 4, 1, 3, 6};
    bubble_sort(yarr2, 9);
    assert(yarr2[0] == 1);
    assert(yarr2[1] == 2);
    assert(yarr2[2] == 3);
    assert(yarr2[3] == 4);
    assert(yarr2[4] == 5);
    assert(yarr2[5] == 6);
    assert(yarr2[6] == 7);
    assert(yarr2[7] == 8);
    assert(yarr2[8] == 9);
    
    // Test case 3
    int yarr3[] = {100, 50, 200, 150};
    bubble_sort(yarr3, 4);
    assert(yarr3[0] == 50);
    assert(yarr3[1] == 100);
    assert(yarr3[2] == 150);
    assert(yarr3[3] == 200);

    printf("All tests passed!\n");
    
    return 0;
}