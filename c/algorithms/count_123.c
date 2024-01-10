#include <assert.h>

void test_count()
{
    int temp_stdout = dup(1);
    int temp_stderr = dup(2);
    freopen("stdout.log", "w", stdout);
    freopen("stderr.log", "w", stderr);
    
    // Test 1: Count number less than 20
    count(10);
    freopen("output.log", "r", stdout);
    assert(strcmp(stdout, "[0123456789]") == 0);
    
    freopen("stdout.log", "w", stdout);
    freopen("stderr.log", "w", stderr);
    
    // Test 2 : Count number greater than 20
    count(22);
    freopen("output.log", "r", stdout);
    assert(strcmp(stdout, "[\n0, \n1, \n2, \n3, \n4, \n5, \n6, \n7, \n8, \n9, \n10, \n11, \n12, \n13, \n14, \n15, \n16, \n17, \n18, \n19, \n20, \n21, \n]") == 0);

    // Restore stdout and stderr
    dup2(temp_stdout, 1);
    dup2(temp_stderr, 2);   
}

int main()
{
     // Run tests
     test_count();

     return 0;
}