#include<stdio.h>

struct M
    {
        char rollNo[11];
        union marksOrGrade
        {
            int marks;
            char grade;
        }a;
    };

int n;
struct M stu[100];

char marksToGrade(int mark)
{
	if(mark>=50)
		return 'P';
	if(mark>=0)
		return 'F';
}

void printResult(void)
{
    
    for(int i=0;i<n;i++)
        {
            if(stu[i].rollNo[0]=='M')
                printf("%s %c\n",stu[i].rollNo,stu[i].a.grade);
            else
                printf("%s %d\n",stu[i].rollNo,stu[i].a.marks);
            
        }
}

int main()
{
    printf("Enter the number of students\n");
    scanf("%d",&n);
    int marks;
    
    for(int i=0;i<n;i++)
    {
        printf("Enter the roll number of student %d\n",i+1);
        scanf("%s",stu[i].rollNo);
        printf("Enter the marks of student %d\n",i+1);
        scanf("%d",&marks);
        
        if(stu[i].rollNo[0]=='M')
            stu[i].a.grade=marksToGrade(marks);
        else
            stu[i].a.marks=marks;
        
    }
    
    printResult();
    
    return 0;
}