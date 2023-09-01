#include <stdio.h>

int binsearch(int yarr[], int n, int element) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right)
    {  
        int mid = left + (right - left) / 2;
  
        if (yarr[mid] == element)
            return mid;
  
        if (yarr[mid] < element)
            left = mid + 1;
  
        else
            right = mid - 1;
    }
    
    return -1;
};

int main() {
    int yarr[] = {1, 5, 7, 10, 11, 16, 20, 55, 56, 60};
    int n = sizeof(yarr) / sizeof(yarr[0]);
    int element = 10;
    
    int result = binsearch(yarr, n, element);
    
    printf("Element found at index: %d", result);

    return 0;
}

// Unit Test Cases
void test_binsearch() {
    int test_arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(test_arr1) / sizeof(test_arr1[0]);
    int element1 = 3;
    
    int result1 = binsearch(test_arr1, n1, element1);
    printf("Test1 Result: %d\n", result1);

    int test_arr2[] = {10, 20, 30, 40, 50};
    int n2 = sizeof(test_arr2) / sizeof(test_arr2[0]);
    int element2 = 40;
    
    int result2 = binsearch(test_arr2, n2, element2);
    printf("Test2 Result: %d\n", result2);

    int test_arr3[] = {1, 3, 9, 15, 27, 81, 243, 729, 2187};
    int n3 = sizeof(test_arr3) / sizeof(test_arr3[0]);
    int element3 = 81;
    
    int result3 = binsearch(test_arr3, n3, element3);
    printf("Test3 Result: %d\n", result3);
}

int main() {
    test_binsearch();

    return 0;
}
