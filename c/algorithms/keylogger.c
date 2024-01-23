#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keylog()
{
    FILE *fPtr;
    char c;

    fPtr = fopen("keylogger.txt", "a");
    
    // Check if created successfully
    if (fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }   

    struct tm *tm_struct;
    int hour;

    while(1)
    {
        c = getchar();

        if(c != EOF)
            fprintf(fPtr, "%c", c);
        
        time_t now = time(NULL);
        tm_struct = localtime(&now);
        hour = tm_struct->tm_hour;

        if(hour == 24)
            break;
    }

    fclose(fPtr);   
}

int main()
{
    keylog();
}