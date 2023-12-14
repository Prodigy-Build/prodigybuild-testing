#include <stdio.h>
#include <stdbool.h>

bool isEvenOrOdd(long num) {
    int rem = num % 2;
    
    if (rem == 0)
        return true;
    else
        return false;
}

int main() {
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    if (isEvenOrOdd(num))
        printf("Even");
    else
        printf("Odd");
      
    return 0;
}

// Unit test cases
void testIsEvenOrOdd() {
    // Test case 1: num = 0 (even)
    bool result = isEvenOrOdd(0);
    if (!result) {
        printf("Test case 1 failed.\n");
    }
    
    // Test case 2: num = 5 (odd)
    result = isEvenOrOdd(5);
    if (result) {
        printf("Test case 2 failed.\n");
    }
    
    // Test case 3: num = 10 (even)
    result = isEvenOrOdd(10);
    if (!result) {
        printf("Test case 3 failed.\n");
    }
    
    // Add more test cases here...
}

int main() {
    // Run unit tests
    testIsEvenOrOdd();
    
    return 0;
}