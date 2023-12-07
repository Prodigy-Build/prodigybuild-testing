#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keylog()
{
    FILE *fPtr;
    fPtr = fopen("keylogger.txt", "w+");
    if (fPtr == NULL) {
        perror("Error opening file");
        exit(1);
    }

    const char *a;
    printf("Please enter a character: ");
    scanf("%c", &a);
    
    if (a != NULL)
        fprintf(fPtr, "%c", *a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if (hour == 24)
        fclose(fPtr);
}

int main()
{
    keylog();
    
    return 0;
}