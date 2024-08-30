#include<stdio.h>

struct M
    {
        char rollNo[11];
        int marks;
        char grade;
    };

int n;
struct M stu[100];

char marksToGrade(int mark)
{
	if(mark>=80)
		return 'A';
	if(mark>=60)
		return 'B';
	if(mark>=50)
		return 'P';
	if(mark>=0)
		return 'F';
}

void printStudent(struct M stu)
{
    printf("%s %d %c\n",stu.rollNo,stu.marks,stu.grade);
}

void printResult(int n)
{
    for(int i=0;i<n;i++)
    {
        printStudent(stu[i]);
    }
}



int main()

{
    printf("Enter the number of students\n");
    scanf("%d",&n);
    
    
    for(int i=0;i<n;i++)
    {
        printf("Enter the roll number of student %d\n",i+1);
        scanf("%s",stu[i].rollNo);
        printf("Enter the marks of student %d\n",i+1);
        scanf("%d",&stu[i].marks);
        stu[i].grade=marksToGrade(stu[i].marks);
    }
    
    printResult(n);
    
    return 0;
}