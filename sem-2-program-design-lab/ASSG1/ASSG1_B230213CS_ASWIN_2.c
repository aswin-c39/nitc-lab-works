#include<stdio.h>
#include<string.h>


int main()
{
    int n;
    char k[101];
    scanf("%d",&n);
    getchar();
    if(n>100000)
    {
        printf("Enter a valid number\n");
        return 0;
    }
    char ch;
    char book[n][101];

    for (int i = 0; i < n; i++)
    {
        
        int ind=0;
        while(ind<100)
        {
            if((ch=getchar())!='\n')
            {
                book[i][ind]=ch;
                ind++;
            }
            else 
                break;
        }
        book[i][ind]='\0';
    }
    
    for (int i = 1; i < n; i++)
    {
        strcpy(k,book[i]);
        int j=i-1;
        while(j>=0 && strcmp(book[j],k)>0)
        {
            strcpy(book[j+1],book[j]);
            j--;
        }
        strcpy(book[j+1],k);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n",book[i]);
    }
    return 0;
 
}