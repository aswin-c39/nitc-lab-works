#include<stdio.h>
#include<string.h>

typedef struct car
{
    char name[50];
    int mil;
}car;

void heapify(car cars[],int n,int i)
{
    int min=i;
    int l=2*i + 1;
    int r=2*i +2;

    if(l<n && cars[l].mil<cars[min].mil)
        min=l;
    if(r<n && cars[r].mil<cars[min].mil)
        min=r;
    
    if(min!=i)
    {
        car temp=cars[i];
        cars[i]=cars[min];
        cars[min]=temp;
        heapify(cars,n,min);

    }
}



void heapsort(car cars[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
        heapify(cars,n,i);
    
    for(int i=n-1;i>0;i--)
    {
        car temp=cars[0];
        cars[0]=cars[i];
        cars[i]=temp;
        heapify(cars,i,0);
    }
}

car input()
{
    char c,name[50]={};
    int count=0;
    while((c=getchar())!=':' && count<50)
    {
        name[count]=c;
        count++;
    }
    char m[4]={};
    count=0;
    while((c=getchar())!='\n' && count<4)
    {
        m[count]=c;
        count++;
    }
    int mil;
    sscanf(m,"%d",&mil);
    car a;
    strcpy(a.name,name);
    a.mil=mil;
    return a;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    car cars[n];

    for(int i=0;i<n;i++)
    {
        cars[i]=input();
    }

    heapsort(cars,n);

    for (int i = 0; i < n; i++)
    {
        printf("%s:%d\n",cars[i].name,cars[i].mil);
    }

    return 0;
        

}