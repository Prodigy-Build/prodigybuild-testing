#include <stdio.h>
#include <assert.h>

// Function to determine if a number is even or odd
int isEvenOrOdd(long num) {
    int rem = num % 2;
    
    if(rem == 0)
        return 1; // Even
    else
        return 0; // Odd
}

// Unit tests
void testIsEvenOrOdd() {
    assert(isEvenOrOdd(2) == 1); // Even number
    assert(isEvenOrOdd(5) == 0); // Odd number
    assert(isEvenOrOdd(0) == 1); // Even number
    assert(isEvenOrOdd(-8) == 1); // Negative even number
    assert(isEvenOrOdd(-11) == 0); // Negative odd number
    assert(isEvenOrOdd(2.5) == 1); // Casting to long: Even number
    assert(isEvenOrOdd(3.9) == 0); // Casting to long: Odd number
}

int main() {
    // Running unit tests
    testIsEvenOrOdd();
    
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    int isEven = isEvenOrOdd(num);
    if (isEven)
        printf("Even");
    else
        printf("Odd");
        
    return 0;
}