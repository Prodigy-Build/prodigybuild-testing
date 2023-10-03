```
#include <stdio.h>
#include <stdbool.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

bool run_fibonacci_tests()
{
    // Test cases
    int test_cases[][2] = {
        {0, 0},
        {1, 1},
        {2, 1},
        {3, 2},
        {4, 3},
        {5, 5},
        {6, 8},
        {7, 13},
        {8, 21},
        {9, 34}
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    bool all_tests_passed = true;

    for (int i = 0; i < num_tests; i++) {
        int input = test_cases[i][0];
        int expected_output = test_cases[i][1];

        int result = fibonacci(input);

        if (result != expected_output) {
            printf("Test case %d failed. Expected %d, got %d\n", i+1, expected_output, result);
            all_tests_passed = false;
        }
    }

    return all_tests_passed;
}

int main()
{
    bool tests_passed = run_fibonacci_tests();

    if (tests_passed) {
        printf("All tests passed\n");
    }
    else {
        printf("Some tests failed\n");
    }

    return 0;
}
```