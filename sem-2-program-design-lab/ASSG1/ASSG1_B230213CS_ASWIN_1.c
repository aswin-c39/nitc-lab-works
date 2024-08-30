#include<stdio.h>

int main()
{
    int n,k,j;
    scanf("%d",&n);
    if(n>100000)
    {
        printf("Enter a valid number\n");
        return 0;
    }
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]>100000 || A[i]<-100000)
            {
                printf("Enter valid number\n");
                return 0;
            }
    }
    for(int i=1;i<n;i++)
    {
        k=A[i];
        j=i-1;
        while(j>=0 && A[j]>k)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=k;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}