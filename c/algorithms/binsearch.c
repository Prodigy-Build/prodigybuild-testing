#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    extern int i;

    if (element == yarr[mid]) {
        printf("%d", mid);
    }

    if (element != yarr[right]) {
        for (i = 0; i < left; i++) {
            if (element == yarr[i]) {
                printf("%d", i);
            }
        }
    }
}

void test_binsearch() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    int arr3[] = {11, 12, 13, 14, 15};
    
    printf("Test 1\n");
    binsearch(arr1, 5, 3); // Output: 2
    printf("\n");
    
    printf("Test 2\n");
    binsearch(arr2, 5, 8); // Output: 2
    printf("\n");
    
    printf("Test 3\n");
    binsearch(arr3, 5, 10); // Output: (nothing)
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Expected at least two command line arguments.\n");
        return 0;
    }

    int size = argc - 1;
    int yarr[size];

    for (int i = 0; i < size; i++) {
        yarr[i] = atoi(argv[i + 1]);
    }

    binsearch(yarr, size, atoi(argv[1]));

    test_binsearch();

    return 0;
}