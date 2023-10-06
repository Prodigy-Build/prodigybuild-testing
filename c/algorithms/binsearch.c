#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;
    
    if(element == mid)
    printf("%d", &mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
            //Does this so that it doesn't print multiple times
            printf("%d", i);
            }
        }
    }
};

int main(int argc, int argv[])
{
    binsearch(argv[0], argv[1]);
}

/* Add unit test cases here */

/* Test case 1:
   Input: yarr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, element = 5
   Expected output: 4
*/

/* Test case 2:
   Input: yarr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, element = 10
   Expected output: 9
*/

/* Test case 3:
   Input: yarr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, element = 2
   Expected output: 1
*/

/* Test case 4:
   Input: yarr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, element = 15
   Expected output: No output
*/
