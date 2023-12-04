#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    const char *a = getchar();
    
    if(a != NULL)
        fprintf(fPtr, "%s", a);
        
    fclose(fPtr);
}

int main()
{
    keylog();
    return 0;
}