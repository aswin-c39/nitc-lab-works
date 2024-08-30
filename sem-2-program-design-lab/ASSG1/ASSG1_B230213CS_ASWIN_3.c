#include<stdio.h>

struct product
{
    char name[10];
    int price;
};


int main()
{
    int n;
    scanf("%d",&n);
    if(n>100000 || n<1)
    {
        printf("Enter a valid number\n");
        return 0;
    }
    struct product p[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s %d",p[i].name,&p[i].price);
        if(p[i].price>100000 || p[i].price<1000)
        {
            printf("Enter a valid number\n");
            return 0;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(p[j].price<p[min].price)
                min=j;
        }
        struct product temp=p[i];
        p[i]=p[min];
        p[min]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%s  ",p[i].name);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",p[i].price);
    }
    return 0;
}