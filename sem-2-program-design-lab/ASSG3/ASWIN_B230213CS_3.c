#include<stdio.h>

int main()
{
    int n,bal=0;
    scanf("%d",&n);
    getchar();
    int A[n][100];
    for(int i=0;i<n;i++)
    {
        int count=0;
        char c;
        int top=0;
        while((c=getchar())!='\n')
        {
            A[i][count]=c;
            count++;
            if(c=='(')
                top++;
            if(c==')')
            {
                if(top!=0)
                    top--;
            }
                

        }
        if(top==0)
            bal++;
    }
    printf("%d",bal);
}