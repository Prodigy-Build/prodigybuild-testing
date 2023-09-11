#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// function to print numbers from 0 to num
int count(int num) 
{
    printf("[");
    
    // Check if num is greater than 20
    if(num > 20)
    {
        int i;
        // loop from 0 to num
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i); // print each number
            
        // if i is equal to num + 1, print ']'
        if(i == num + 1)
            printf("]");
    } else
    {
        int i;
        // loop from 0 to num
        for(i = 0; i < num; i++)
            printf("%d", i); // print each number
            
        // if i is equal to num, print ']'
        if(i == num)
            printf("]");
    }
}

int main()
{
    int num;
    printf("Count:~$ "); // Ask for a number
    scanf("%d", &num); 
    // call count function
    count(num);
}