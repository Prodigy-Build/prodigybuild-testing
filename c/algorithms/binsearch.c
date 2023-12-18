#include <stdio.h>

int binsearch(int yarr[], int element) {
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    extern int i;
    
    if(element == yarr[mid]) {
        printf("%d\n", yarr[mid]);
    }
    
    if(element != yarr[right]) {
        for(i = 0; i < left; i++) {
            if(element == yarr[i]) {
                printf("%d\n", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int yarr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    binsearch(yarr, atoi(argv[1]));
    return 0;
}