#include<stdio.h>
#include<string.h>
typedef struct students
{
    char rollno[11];
    int marks;
    char result[5]; 
}Student;

int isValidRollnumber(char *str)
{
    if(strlen(str)>8)
        return 0;
    if(*(str+0)=='B' && *(str+1)=='C' && *(str+2)=='S' && *(str+3)=='2')
    {
        if(*(str+4)>='0' && *(str+4)<='3')
        {
            if(*(str+5)>='0' && *(str+5)<='9')
            {
                if(*(str+6)>='0' && *(str+6)<='9')
                {
                    if(*(str+7)>='0' && *(str+7)<='9')
                        return 1;
                }
            }

        }
    }
    return 0;
}

void assignResult(Student *s)
{
    if(s -> marks > 40)
        strcpy(s->result, "Pass");
    else
        strcpy(s->result,"Fail");
}
void printStudent(Student *s)
{
    printf("%s %d %s\n",s->rollno,s->marks,s->result);
}

int main()
{
    Student s1;
    scanf("%s",s1.rollno);
    scanf("%d",&s1.marks);
    Student *ptr=&s1;
    if(isValidRollnumber(s1.rollno)==0)
        printf("INVALID\n");
    else
    {
    
        assignResult(ptr);
        printStudent(ptr);
    }
    return 0;
}