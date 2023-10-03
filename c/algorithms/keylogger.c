#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stddef.h>
#include <stdarg.h>

void test_keylog();
void test_checkForNull();
void test_checkHour();
void test_logToFile();
void test_closeFile();

int keylog();
void checkForNull(const char *);
int checkHour(int);
void logToFile(FILE *, const char *);
void closeFile(FILE *);

int main()
{
    test_keylog();
    return 0;
}

void test_keylog()
{
    test_checkForNull();
    test_checkHour();
    test_logToFile();
    test_closeFile();
}

void test_checkForNull()
{
    const char *str = "abcdefghijklmnopqrstuvwxyz";
    checkForNull(str);
}

void test_checkHour()
{
    int hour = 24;
    checkHour(hour);
}

void test_logToFile()
{
    FILE *fPtr = fopen("keylogger.txt", "w+");
    const char *a = "abcdefghijklmnopqrstuvwxyz";
    logToFile(fPtr, a);
}

void test_closeFile()
{
    FILE *fPtr = fopen("keylogger.txt", "w+");
    closeFile(fPtr);
}

int keylog()
{
    FILE *fPtr = fopen("keylogger.txt", "w+");
    logToFile(fPtr, a);
    int hour = checkHour(hour);
    closeFile(fPtr);
    return 0;
}

void checkForNull(const char *str)
{
    if (str != NULL)
    {
        printf("String is not null\n");
    }
    else
    {
        printf("String is null\n");
    }
}

int checkHour(int hour)
{
    if (hour == 24)
    {
        printf("Hour is equal to 24\n");
    }
    else
    {
        printf("Hour is not equal to 24\n");
    }
    return hour;
}

void logToFile(FILE *fPtr, const char *a)
{
    if (fPtr != NULL)
    {
        fprintf(fPtr, a);
    }
}

void closeFile(FILE *fPtr)
{
    fclose(fPtr);
}