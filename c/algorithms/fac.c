#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fak(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (n < 0) {
        return 1;
        exit(1);
    }
    return n * fak(n-1);
}

// Test Case for fak function
void test_fak() {
    // Test case 1
    int result1 = fak(1);
    printf("fak(1): %d\n", result1);
    
    // Test case 2
    int result2 = fak(2);
    printf("fak(2): %d\n", result2);
    
    // Test case 3
    int result3 = fak(3);
    printf("fak(3): %d\n", result3);
    
    // Test case 4
    int result4 = fak(4);
    printf("fak(4): %d\n", result4);
    
    // Test case 5
    int result5 = fak(5);
    printf("fak(5): %d\n", result5);
    
    // Test case 6 (negative number)
    int result6 = fak(-1);
    printf("fak(-1): %d\n", result6);
}

// Main function
int main() {
    // Run the test cases
    test_fak();
    
    return 1;
}