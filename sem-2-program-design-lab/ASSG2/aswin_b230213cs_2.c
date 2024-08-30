#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    char name[10];
    int marks;

}student;

int main()
{
    int n,r;
    scanf("%d",&n);
    getchar();
    student *stu = (student*)malloc(n*sizeof(student));
    if(stu == NULL)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", stu[i].name, &stu[i].marks);
        if(stu[i].marks<0 || stu[i].marks>100)
            return 0;
    }

    scanf("%d",&r);

    if(r>0 && r<=n)
    {
        for (int i = 0; i < n; i++)
        {
            int rank=1;
            for (int j = 0; j < n; j++)
            {
                if(stu[i].marks<stu[j].marks)
                {
                    rank++;
                }
            }
            if(rank==r)
            {
                printf("%s %d\n",stu[i].name,stu[i].marks);
                break;
            }
            
        }
        
    }

    free(stu);
    return 0;

}