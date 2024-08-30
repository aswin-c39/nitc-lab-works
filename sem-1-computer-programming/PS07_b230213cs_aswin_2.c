#include<stdio.h>

int n,marks[100][3];

int highestMark(int a)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(marks[i][a]>max)
            max=marks[i][a];
    }
    return max;
}

int lowestMark(int a)
{
    int min=marks[0][a];
    for(int i=0;i<n;i++)
    {
        if(marks[i][a]<min)
            min=marks[i][a];
    }
    return min;
}

float averageMarks(int a)
{
    int sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=marks[i][a];
    }
    return (float)sum/n;
}

int totalMark(int a)
{
    int sum=0;
    for(int i=0;i<3;++i)
    {
        sum+=marks[a][i];
    }
    return sum;
}


int main()
{
    printf("Enter the number of students\n");
    scanf("%d",&n);
    printf("Enter the marks of students\n");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<3;++j)
        {
            int mark;
            scanf("%d",&mark);
            marks[i][j]=mark;
        }
        
    }
    int choice,id;
    //printf("%d %d %d %f",highestMark(0),lowestMark(1),totalMark(3),averageMarks(0));
    while(1)
    {
    printf("Please enter a number indicating your choice\n");
    printf("1: highest mark in a course\n");
    printf("2: lowest mark in a course\n");
    printf("3: average marks for a course\n");
    printf("4: total marks for a course\n");
    printf("0: exit\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter course id:");
        scanf("%d",&id);
        printf("Highest marks in course %d : %d\n",id,highestMark(id));
    }
    if(choice==2)
    {
        printf("Enter course id:");
        scanf("%d",&id);
        printf("lowest marks in course %d : %d\n",id,lowestMark(id));
    }
    if(choice==3)
    {
        printf("Enter course id:");
        scanf("%d",&id);
        printf("Highest marks in course %d : %f\n",id,averageMarks(id));
    }
    if(choice==4)
    {
        printf("Enter the student id:");
        scanf("%d",&id);
        printf("Total mark of student %d : %d\n",id,totalMark(id));
    }
    if(choice==0)
     break;
    
    
    }
    return 0;
}