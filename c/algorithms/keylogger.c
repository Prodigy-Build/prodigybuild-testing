#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    const char *a = (const char*)malloc(2 * sizeof(char));
    scanf("%1s", a);
    
    if(a != NULL)
    {
        fprintf(fPtr, "%s", a);
        free((void*)a);
    }
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
}

int main()
{
    keylog();
    return 0;
}