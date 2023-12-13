#include <stdio.h>
#include <stdlib.h>

void fib()
{
    long a;
    long b;

    for (a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld", a, b);
    }

    if (b == sizeof(long))
    {
        exit(1);
    }
}

int main()
{
    fib();
    return 0;
}

//Unit test cases

void test_fib()
{
    //initialize standard output buffer
    char buffer[256];
    freopen("output.txt", "w", stdout);

    //run the function
    fib();

    //capture the output
    fclose(stdout);
    freopen("CON", "w", stdout);
    freopen("output.txt", "r", stdin);

    //check the output
    fgets(buffer, sizeof(buffer), stdin);
    assert(strcmp(buffer, "1\n 1") == 0);    
}

int main()
{
    test_fib();
    return 0;
}