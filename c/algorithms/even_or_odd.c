

# Unit Test for `even_or_odd.c`

The following unit test is written using the [CUnit](http://cunit.sourceforge.net/) framework.

```c
#include <stdio.h>
#include <CUnit/CUnit.h>

void test_even_or_odd(void)
{
    long num;
    int rem;
    
    // Test even number
    num = 4;
    rem = num % 2;
    CU_ASSERT_EQUAL(rem, 0);
    
    // Test odd number
    num = 5;
    rem = num % 2;
    CU_ASSERT_EQUAL(rem, 1);
}

int main()
{
    CU_pSuite pSuite = NULL;
    
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    
    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* add the tests to the suite */
    if (
        (NULL == CU_add_test(pSuite, "test_even_or_odd", test_even_or_odd))
    )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
```