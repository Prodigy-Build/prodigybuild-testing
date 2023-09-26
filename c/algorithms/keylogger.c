```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "a");

    const char *a = fgets(NULL, 1, stdin);

    if(a != NULL)
        fprintf(fPtr, "%s", a);

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
```