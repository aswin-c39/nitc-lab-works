#include<stdio.h>
typedef struct 
{
    int id;
    int p;
}job;

typedef struct
{
    job jobs[20];
    int size;
}Q;

void swap(job *a,job *b)
{
    job temp=*a;
    *a=*b;
    *b=temp;
}

void heapifyup(Q *que,int id)
{
    int parent =(id-1)/2;
    if(parent>=0 && que->jobs[parent].p<que->jobs[id].p)
    {
        swap(&que->jobs[parent],&que->jobs[id]);
        heapifyup(que,parent);
    }
}

void heapifydown(Q *que,int id)
{
    int l=2*id+1;
    int r=2*id+2;
    int max=id;

    if(l<que->size && que->jobs[l].p>que->jobs[max].p)
        max=l;
    if(r<que->size && que->jobs[r].p>que->jobs[max].p)
        max=r;

        if(max!=id)
        {
            swap(&que->jobs[id],&que->jobs[max]);
            heapifydown(que,max);
        }

}

void add(Q *que,int id,int p)
{
    if(que->size>=20)
    {
        printf("-1\n");
        return ;
    }
    job new={id,p};
    que->jobs[que->size]=new;
    que->size++;
    heapifyup(que,que->size-1);
}

void schedule(Q *que)
{
    if(que->size == 0)
    {
        printf("-1\n");
        return;
    }
    job sch_job=que->jobs[0];
    printf("%d\n",sch_job.id);
    que->jobs[0]=que->jobs[que->size-1];
    que->size--;
    heapifydown(que,0);
}

void next_job(Q *que)
{
    if(que->size==0)
    {
        printf("-1\n");
        return;
    }
    job next_job=que->jobs[0];
    printf("%d\n",next_job.id);
}

void replace_priority(Q *que,int id,int np)
{
    int found=0;
    for(int i=0;i<que->size;i++)
    {
        if(que->jobs[i].id==id)
        {
            found=1;
            que->jobs[i].p=np;
            heapifydown(que,i);
            break;
        }
    }
    if(!found)
        printf("-1\n");
}

void display(Q *que)
{
    if(que->size==0)
    {
        printf("-1\n");
        return;
    }
    
    for(int i=0;i<que->size;i++)
    {
        printf("%d %d\n",que->jobs[i].id,que->jobs[i].p);
    }
}

int main()
{
    char choice='A';
    Q que={{},0};
    int end =0;
    while (choice!='e')
    {
        scanf("%c",&choice);
        switch (choice)
        {
        case 'a':
        {
            int id,p;
            scanf("%d%d",&id,&p);
            add(&que,id,p);
            break;
        }

        case 's':
        {
            schedule(&que);
            break;
        }

        case 'n':
        {
            next_job(&que);
            break;
        }

        case 'r':
        {
            int id,np;
            scanf("%d %d",&id,&np);
            replace_priority(&que,id,np);
            break;
        }
        
        case 'd':
            display(&que);
            break;

        case 'e':
            break;
        default:
            break;
        }
    }
    return 0;

}