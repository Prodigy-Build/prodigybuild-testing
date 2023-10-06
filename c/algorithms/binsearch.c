 #include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = 10 - left;
    extern int i;
    
    if(element == yarr[mid])
        printf("%d", &mid);
    
    if(element != yarr[right-1])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[10];
    int element;
    
    // read yarr and element from command line arguments
    
    binsearch(yarr, element);
    
    return 0;
}