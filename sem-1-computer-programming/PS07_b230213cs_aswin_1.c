#include<stdio.h>

int n;
int M[100];
int G[100];

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

int gradeCount(char grade)
{
	int count=0;
	for(int i=0;i<n;i++)
		{
		if(G[i]==grade)
			count++;
		}
	
	return count;
}

void printGradeCount(void)
{
	printf("Grade	Count\n");
	printf("  %c	  %d\n",'A',gradeCount('A'));
	printf("  %c	  %d\n",'B',gradeCount('B'));
	printf("  %c	  %d\n",'P',gradeCount('P'));
	printf("  %c	  %d\n",'F',gradeCount('F'));
}


int main()
{
	int mark;
	printf("Enter number of students\n");
	scanf("%d",&n);
	printf("Enter marks of students\n");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&mark);
		M[i]=mark;
	}
	for(int i=0;i<n;++i)
		G[i]=marksToGrade(M[i]);
		
	printGradeCount();
	gradeCount('A');
	return 0;
	
	
}
