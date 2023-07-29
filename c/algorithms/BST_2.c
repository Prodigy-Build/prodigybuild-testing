

#include <stdio.h>
#include <assert.h>

int linsearch(int *yarr, int val)
{
    for(int i = 0; i < sizeof(yarr); i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }    
        else
        {
          return 1;
        }
    }
}

// Unit Test Cases
void test_linsearch() {
    int yarr[] = {1, 2, 3, 4, 5};
    assert(linsearch(yarr, 3) == 0);
    assert(linsearch(yarr, 6) == 1);
}

int main() {
    test_linsearch();
    printf("All tests passed!\n");
    return 0;
}