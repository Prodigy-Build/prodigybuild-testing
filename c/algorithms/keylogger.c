#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keylog()
{
    FILE *fPtr = fopen("keylogger.txt", "w");
    
    if (fPtr != NULL)
    {
        const char *a = "Hello, world!";
        fprintf(fPtr, "%s", a);
        fclose(fPtr);
    }
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if (hour == 24)
        remove("keylogger.txt");
}

int main()
{
    keylog();
    
    return 0;
}