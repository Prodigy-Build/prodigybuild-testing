#include <stdio.h>

void test_binsearch() {
  int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Test case 1: element is in the middle
  int element1 = 5;
  int result1 = binsearch(yarr, element1);
  printf("Result 1: %d\n", result1);

  // Test case 2: element is in the left half
  int element2 = 2;
  int result2 = binsearch(yarr, element2);
  printf("Result 2: %d\n", result2);

  // Test case 3: element is in the right half
  int element3 = 9;
  int result3 = binsearch(yarr, element3);
  printf("Result 3: %d\n", result3);

  // Test case 4: element is not found
  int element4 = 13;
  int result4 = binsearch(yarr, element4);
  printf("Result 4: %d\n", result4);
}

int binsearch(int yarr[10], int element) {
  int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
  int left = mid;
  int right = sizeof(yarr) / sizeof(yarr[0]);

  if (element == yarr[mid])
    return mid;

  if (element != yarr[right]) {
    for (int i = 0; i < left; i++) {
      if (element == yarr[i]) {
        // Does this so that it doesn't print multiple times
        return i;
      }
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  test_binsearch();
  return 0;
}