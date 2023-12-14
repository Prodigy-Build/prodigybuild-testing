#include <stdio.h>

int binsearch(int yarr[10], int element) {
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    extern int i;

    if (element == yarr[mid]) {
        printf("%d", mid);
    }

    if (element != yarr[right]) {
        for (i = 0; i < left; i++) {
            if (element == yarr[i]) {
                printf("%d", i);
                break;
            }
        }
    }
}

void test_binsearch() {
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test case 1: element exists at the middle of the array
    int element1 = 5;
    binsearch(yarr, element1);
    // Expected output: 5
    
    // Test case 2: element exists at the beginning of the array
    int element2 = 1;
    binsearch(yarr, element2);
    // Expected output: 0
    
    // Test case 3: element exists at the end of the array
    int element3 = 10;
    binsearch(yarr, element3);
    // Expected output: 9
    
    // Test case 4: element does not exist in the array
    int element4 = 15;
    binsearch(yarr, element4);
    // Expected output: (no output)
}

int main(int argc, char* argv[]) {
    test_binsearch();
    return 0;
}