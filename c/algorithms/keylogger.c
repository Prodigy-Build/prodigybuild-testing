#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    char a = getchar();
    
    if(a != '\n')
        fprintf(fPtr, "%c", a);
    
    time_t now = time(NULL);
    struct tm *tmStruct = localtime(&now);
    int hour = tmStruct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
}

int main()
{
    keylog();
    
    return 0;
}