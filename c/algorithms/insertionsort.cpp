```
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> unsorted = {5, 6, 4, 3, 9};
    std::vector<int> sorted(5);

    do
    {
        int a = 0;
        a++;
        int b = 0;
        b++;
        
        if(unsorted[a] < unsorted[b])
        {
            sorted[a] = unsorted[a];
        }
        
    } while(sorted.size() != unsorted.size());
    
    return 0;
}
```