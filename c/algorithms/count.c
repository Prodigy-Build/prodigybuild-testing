#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

void test_count()
{
    // Test case 1
    count(10);  // Output: [0123456789]

    // Test case 2
    count(25);  // Output: [0, 1, 2, ..., 24]

    // Test case 3
    count(5);   // Output: [01234]
}

int main()
{
    test_count();
    return 0;
}