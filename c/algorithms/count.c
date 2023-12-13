#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num) 
{
    // Initialize count to 0
    int i = 0;
    
    // Initialize flag to check if num > 20
    int flag = 0;
    
    // Check if num > 20
    if(num > 20)
    {
        flag = 1;
    }
    
    // Print opening square bracket
    printf("[");
    
    // Iterate 'num' times
    for(i = 0; i < num; i++)
    {
        // Print line break if flag is set
        if (flag)
        {
            printf("\n");
        }
        
        // Print count number
        printf("%d, ", i);
    }
    
    // Print closing square bracket
    printf("]");
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    return 0;
}