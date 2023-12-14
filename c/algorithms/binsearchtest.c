```
// Unit Test 1: Testing when element is found at the middle index
int test_case_1() {
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 5;
    
    int result = binsearch(yarr, element);
    
    if (result == 5) {
        return 0; // test passed
    } else {
        return 1; // test failed
    }
}

// Unit Test 2: Testing when element is found at a left index
int test_case_2() {
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 3;

    int result = binsearch(yarr, element);

    if (result == 3) {
        return 0; // test passed
    } else {
        return 1; // test failed
    }
}

// Unit Test 3: Testing when element is found at multiple left indices
int test_case_3() {
    int yarr[10] = {1, 2, 3, 2, 5, 2, 7, 8, 9, 10};
    int element = 2;

    int result = binsearch(yarr, element);

    if (result == 1) {
        return 0; // test passed
    } else {
        return 1; // test failed
    }
}

// Unit Test 4: Testing when element is not found in the array
int test_case_4() {
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 11;

    int result = binsearch(yarr, element);

    if (result == -1) {
        return 0; // test passed
    } else {
        return 1; // test failed
    }
}

// Run all the unit tests
int main() {
    int test_results[4];
    test_results[0] = test_case_1();
    test_results[1] = test_case_2();
    test_results[2] = test_case_3();
    test_results[3] = test_case_4();

    for (int i = 0; i < 4; i++) {
        if (test_results[i] == 0) {
            printf("Test case %d passed\n", i+1);
        } else {
            printf("Test case %d failed\n", i+1);
        }
    }

    return 0;
}
```