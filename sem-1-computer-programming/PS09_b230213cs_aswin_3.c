#include<stdio.h>

void readMarks(int M[],int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&M[i]);
    }

}

void marksToGrade(int M[],char G[],int n)
{
    for (int i = 0; i < n; i++)
    {
        char *ptr = &G[i];
        if(M[i]>=80 && M[i]<=100)
            *ptr='A';
        if(M[i]>=60 && M[i]<80)
            *ptr='B';
        if(M[i]>=50 && M[i]<60)
            *ptr='P';
        if(M[i]>=0 && M[i]<50)
            *ptr='F';    
    }
    
}

void printGradeCount(char G[],int n)
{
    int counta=0,countb=0,countp=0,countf=0;
    for(int i=0;i<n;i++)
    {
        if(G[i]=='A')
            counta++;
        if(G[i]=='B')
            countb++;
        if(G[i]=='P')
            countp++;
        if(G[i]=='F')
            countf++;
    }
    printf("A   %d\nB   %d\nP   %d\nF   %d",counta,countb,countp,countf);
}

int main()
{
    int n,M[100];
    char G[100];
    scanf("%d",&n);

    readMarks(M,n);
    marksToGrade(M,G,n);
    printGradeCount(G,n);
    
    return 0;
}