#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// Unit test cases

void testCount()
{
    // Test case 1
    int num1 = 10;
    printf("Expected output for num1: [0123456789]\n");
    printf("Actual output for num1: ");
    count(num1);

    // Test case 2
    int num2 = 25;
    printf("Expected output for num2: \n0, \n1, \n2, \n3, \n4, \n5, \n6, \n7, \n8, \n9, \n10, \n11, \n12, \n13, \n14, \n15, \n16, \n17, \n18, \n19, \n20, \n21, \n22, \n23, \n24, \n25\n]\n");
    printf("Actual output for num2: ");
    count(num2);
}

int main()
{
    testCount();
    return 0;
}