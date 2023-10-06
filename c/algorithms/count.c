#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        if(i == num + 1)
            printf("]");
    } else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}

void test_count()
{
    // Test Case 1
    printf("Test Case 1\n");
    count(5); // expected output: [01234]
    
    // Test Case 2
    printf("Test Case 2\n");
    count(25); // expected output: \n0, \n1, \n2, \n3, \n4, \n5, \n6, \n7, \n8, \n9, \n10, \n11, \n12, \n13, \n14, \n15, \n16, \n17, \n18, \n19, \n20, \n21, \n22, \n23, \n24, \n]
}

int main()
{
    test_count();
    return 0;
}