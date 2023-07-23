Below is the changes I suggest for the count.c in terms of the usability of the code.

c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count(int num) // change return type void to compile without warnings
{
    printf("[");

    int i; // declare outside the if condition to make the code DRY.
    for(i = 0; i < num; i++)
    {
        if(num > 20) // put this if condition within for loop to make sure it checks for each iteration
        {
            printf("\n%d, ", i);
        } else
        {
            printf("%d,", i);
        }
    }
    
    printf("%d]", i); // change this line to avoid if condition and make it DRY.
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}


Writing unit tests in C is a broad topic and usually requires a framework like Check or Unity to carry out. However, in your case, it seems like the function or tool that you want to test is count. A simple way would be adding assertions assuming we're using the assert library. 

Add this line on top of your c file:
c
#include <assert.h>


Then, here's a simple way to test counting from the main function.

c
int main()
{
    // Run tests first
    testCount();

    // Actual application
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}

void testCount()
{
    // Here goes our assertions we want to check
    // You may need to adjust this according to your needs.
    assert(count(5) == "[0,1,2,3,4,5]");
    assert(count(25) == "[\n0, \n1, ...]");
    printf("All tests passed!\n");
}


Remember this might not work straightforward for your case. Testing in C especially functions with side effects (like printing to standard output) is a broad topic and might require more complex setup.