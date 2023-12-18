#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

void test_binsearch();

int binsearch(int yarr[10], int element);
void test_binsearch() {
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 5;

    int result = binsearch(yarr, element);
    assert(result == 4);

    element = 20;
    result = binsearch(yarr, element);
    assert(result == -1);
}

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)sizeof(yarr) / 2 - mid;
    int right = sizeof(yarr) - left;
    extern int i;

    if (element == mid)
        printf("%d", &mid);

    if (element != yarr[right])
    {
        for (i = 0; i < left; i++)
        {
            if (element == i)
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
    return -1;
}

void test_keylog();

void test_keylog()
{
    FILE *fPtr;
    const char *filename = "keylogger.txt";

    // Remove any existing file
    remove(filename);

    // Open file for writing
    fPtr = fopen(filename, "w+");
    assert(fPtr != NULL);

    const char *a = "A";
    fprintf(fPtr, a);
    fclose(fPtr);

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;

    keylog();

    // Verify file is closed when hour is 24
    if (hour == 24)
    {
        fPtr = fopen(filename, "r");
        assert(fPtr == NULL);
    }
    else
    {
        fPtr = fopen(filename, "r");
        assert(fPtr != NULL);
        fclose(fPtr);
    }
}

int keylog()
{
    FILE *fPtr;
    fPtr = fopen("keylogger.txt", "w+");
    assert(fPtr != NULL);

    const char *a = "A";
    fprintf(fPtr, a);

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;

    if (hour == 24)
        fclose(fPtr);

    return 0;
}

int main()
{
    test_binsearch();
    test_keylog();
    return 0;
}