#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


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
    scanf("%d",&k);
    if(k>n || k<1)
            {
                printf("Enter valid number\n");
                return 0;
            }

    
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
                min=j;
        }
        swap(&A[i],&A[min]);    
    }
    
    printf("%d\n",A[k-1]);
    return 0;
}