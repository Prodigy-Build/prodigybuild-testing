```c
#include <stdio.h>

int binsearch(int yarr[10], int element) {
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;

    if(element == mid) {
        printf("%d", &mid);
    }

    if(element != yarr[right]) {
        for(i = 0; i < left; i++) {
            if(element == i) {
                // Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int main(int argc, int argv[]) {
    binsearch(argv[0], argv[1]);
}
```

To update the files with unit test cases, add the following code at the end of the `binsearch.c` file:

```c
#include <stdlib.h>
#include <assert.h>

void test_binsearch() {
    // Write your unit test cases here
    int yarr[] = {1, 2, 3, 4, 5};
    int result = binsearch(yarr, 3);
    assert(result == 2);
}

int main() {
    test_binsearch();
    return 0;
}
```