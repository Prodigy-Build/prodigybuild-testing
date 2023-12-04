```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int keylog() {
    FILE *fPtr;
    fPtr = fopen("keylogger.txt", "a+");

    const char *a = fgets();

    if (a != NULL)
        fprintf(fPtr, "%s", a);

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;

    if (hour == 24)
        fclose(fPtr);
}

int main() {
    keylog();
}
```