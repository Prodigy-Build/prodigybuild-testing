#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

void test_count() {
    printf("Testing count function...\n");
    
    // Test case 1: num is greater than 20
    printf("Test case 1: num > 20\n");
    printf("Expected Output:\n[0, \n1, \n2, \n3, \n4, \n5, \n6, \n7, \n8, \n9, \n10, \n11, \n12, \n13, \n14, \n15, \n16, \n17, \n18, \n19, \n]\n");
    printf("Actual Output:\n");
    count(21);
    printf("\n\n");

    // Test case 2: num is less than or equal to 20
    printf("Test case 2: num <= 20\n");
    printf("Expected Output:\n[012345678910111213141516171819]\n");
    printf("Actual Output:\n");
    count(20);
    printf("\n\n");
}

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
    test_count();
    
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}