#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=h+1;
    for(int j=h;j>l;j--)
    {
        if(a[j]>pivot)
        {
            i--;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i-1],&a[l]);
    return i-1;
}

void quicksort(int a[],int l,int h)
{
    if (l<h)
    {
        int p=partition(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    if(n<0 || n>10000)
    {
        printf("Error : n is out of range\n");
        return 0;
    }
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0 || a[i]>1000000)
        {
            printf("Error : element is out of range\n");
            return 0;
        }
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}