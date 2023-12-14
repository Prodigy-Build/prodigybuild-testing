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

// Unit test cases
void test_bubble_sort() 
{
    int test_array_1[] = {3, 1, 4, 2, 5};
    int expected_array_1[] = {1, 2, 3, 4, 5};
    
    bubble_sort(test_array_1, 5);
    
    for (int i = 0; i < 5; i++) {
        assert(test_array_1[i] == expected_array_1[i]);
    }
    
    int test_array_2[] = {9, 4, 8, 7, 6, 1, 2};
    int expected_array_2[] = {1, 2, 4, 6, 7, 8, 9};
    
    bubble_sort(test_array_2, 7);
    
    for (int i = 0; i < 7; i++) {
        assert(test_array_2[i] == expected_array_2[i]);
    }
}

int main(void) 
{
    // Run unit tests
    test_bubble_sort();

    return 0;
}