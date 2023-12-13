#include <stdio.h>

int even_or_odd(long num) {
    int rem = num % 2;
    
    if (rem == 0)
        return 1;
    else
        return 0;
}

void test_even_or_odd() {
    // Test case 1: Even number
    if (even_or_odd(10) != 1) {
        printf("Test case 1 Failed\n");
    }
    
    // Test case 2: Odd number
    if (even_or_odd(7) != 0) {
        printf("Test case 2 Failed\n");
    }
    
    // Test case 3: Negative even number
    if (even_or_odd(-4) != 1) {
        printf("Test case 3 Failed\n");
    }
    
    // Test case 4: Negative odd number
    if (even_or_odd(-9) != 0) {
        printf("Test case 4 Failed\n");
    }
    
    // Test case 5: Zero
    if (even_or_odd(0) != 1) {
        printf("Test case 5 Failed\n");
    }
    
    printf("All test cases passed\n");
}

int main() {
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    if (even_or_odd(num) == 1) {
        printf("Even");
    } else {
        printf("Odd");
    }
    
    test_even_or_odd(); // Run unit tests
    
    return 0;
}