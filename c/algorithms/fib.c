#include <stdio.h>
#include <stdlib.h> /* include stdlib.h for the exit() function*/

int main()
{
    long a;
    long b;
    
    for(a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld", a, b); /* remove the '&' from printf arguments */
    }
    
    if(b == sizeof(long))
    {
        exit(1);
    }
    return 0; /* add return 0; at the end of the main() function */
}