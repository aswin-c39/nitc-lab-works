#include<stdio.h>

void merge(int A[],int l,int mid,int u)
{
    int i,j,k;
    int n1 = mid-l+1;
    int n2 = u-mid;
    int lA[n1],rA[n2];
    for(i=0;i<n1;i++)
        lA[i]=A[l+i];
    for ( j = 0; j < n2; j++)
        rA[j]=A[mid+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(lA[i]<=rA[j])
        {
            A[k]=lA[i];
            i++;
        }
        else{
            A[k]=rA[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        A[k]=lA[i];
        i++;k++;
    }

    while(j<n2)
    {
        A[k]=rA[j];
        j++;k++;
    }
        
}

void mergesort(int A[],int l,int u)
{
if(l<u)
    {
        int mid=(l+u)/2;
        mergesort(A,l,mid);
        mergesort(A,mid+1,u);
        merge(A,l,mid,u);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    if(n<0 || n>100000)
    {
        printf("Error : n is out of range\n");
        return 0;
    }
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]<0 || A[i]>100000)
        {
            printf("Error : element is out of range\n");
            return 0;
        }
    }
    mergesort(A,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
    
}