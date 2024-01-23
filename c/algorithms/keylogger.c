#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "a+");

    if (fPtr == NULL)
    {
        return -1;
    }

    int c;
    while ((c = getchar()) != EOF)
    {
        fputc(c, fPtr);

        fflush(fPtr);

        time_t now = time(NULL);
        struct tm *tm_struct = localtime(&now);

        if(tm_struct->tm_hour == 24)
        break;
    }

    fclose(fPtr);
    return 0;
}

int main()
{
    return keylog();
}