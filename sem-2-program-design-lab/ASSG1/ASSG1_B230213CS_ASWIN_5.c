#include<stdio.h>


int main()
{
    int n,count=0;
    scanf("%d",&n);
    if(n<1 || n>100000)
    {
        printf("Enter a valid number\n");
        return 0;
    }
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<1 || arr[i]>100000)
        {
            printf("Enter a valid number\n");
            return 0;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                count++;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n%d",count);
    return 0;
    

}