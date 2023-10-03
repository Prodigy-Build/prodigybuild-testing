/*
    Write unit tests
*/

#include <stdio.h>
#include <assert.h>

// Function to check if a number is even or odd
void CheckEvenOrOdd(long num) {
    int rem = num % 2;
    
    if (rem == 0)
        printf("%ld is Even\n", num);
    else
        printf("%ld is Odd\n", num);
}

// Unit tests for CheckEvenOrOdd function
void unitTests() {
    // Test with even number
    int evenNum = 8;
    printf("Testing with %d\n", evenNum);
    CheckEvenOrOdd(evenNum);
    
    // Test with odd number
    int oddNum = 15;
    printf("Testing with %d\n", oddNum);
    CheckEvenOrOdd(oddNum);
    
    // Test with negative even number
    int negEvenNum = -10;
    printf("Testing with %d\n", negEvenNum);
    CheckEvenOrOdd(negEvenNum);
    
    // Test with negative odd number
    int negOddNum = -5;
    printf("Testing with %d\n", negOddNum);
    CheckEvenOrOdd(negOddNum);
}

int main() 
{
    // Running unit tests
    unitTests();

    return 0;
}