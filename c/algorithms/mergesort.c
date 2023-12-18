// function to merge the sub-arrays
void merge(int a[],int low,int mid ,int high)
{
    int b[20]; //same size of a[]
    int i, j, k;
    i = low, j = mid + 1,k = low;
    while(i <= mid && j <= high)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
           b[k++]=a[j++]; //copying the elements 
    }
    while (i<=mid)
        b[k++]=a[i++];
    while (j<=high) 
        b[k++]=a[j++];
    for (k=low;k<=high;k++)
        a[k]=b[k];
}