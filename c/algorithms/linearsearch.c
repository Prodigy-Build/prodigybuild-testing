```c/algorithms/linearsearch.c```

```c
#include <stdio.h>

int linsearch(int *yarr, int val)
{
    for(int i = 0; i < sizeof(yarr); i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }    
        else
        {
          return 1;
        }
    }
}

int main()
{
    const char *yarr[2] = {"Shluck much", "much Shluck"};
    const char *val = "Shluck Much";
    linsearch(yarr, val);
}
```