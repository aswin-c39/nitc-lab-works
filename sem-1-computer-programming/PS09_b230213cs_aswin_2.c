#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int smallest(int a[5])
{
    int min=a[0];
    int pos=0;
    for(int i=0;i<5;i++)
    {
        if(a[i]<min)
        {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}
int main()
{
    int arr[5];
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }

    int x = smallest(arr);

    swap(&arr[x],&arr[0]);
    
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}