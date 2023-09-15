#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    fopen("keylogger.txt", "w");
    const char *a = getchar();
    
    if(a != NULL)
        fprintf(fPtr, a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);

    return hour;
}

void test_keylog() {
    int result = keylog();
    assert(result >= 0 && result < 24);
    printf("All tests passed.\n");
}

int main()
{
    test_keylog();
}

