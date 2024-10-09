#include<stdio.h>
#define MAX 1000

typedef struct job{
    int id;
    int priority;
}job;

void swap(job *a,job *b)
{
    job temp = *a;
    *a = *b;
    *b = temp;
}

int search(job jobs[],int id,int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(jobs[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void Add(job jobs[],int id,int p,int *size)
{
    job j;
    j.id = id;
    j.priority = p;

    jobs[*size] = j;

    int i = (*size);
    (*size)++;
    while(i > 0 && jobs[i].priority < jobs[(i-1)/2].priority)
    {
        swap(&jobs[i],&jobs[(i-1)/2]);
        i = (i-1)/2;
    } 
}

void minheapify(job jobs[],int i,int size)
{
    int min = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && jobs[left].priority < jobs[min].priority)
        min = left;
    
    if(right < size && jobs[right].priority < jobs[min].priority)
        min = right;

    if(min != i)
    {
        swap(&jobs[min],&jobs[i]);
        minheapify(jobs,min,size);
    }
}

void Schedule(job jobs[],int *size)
{
    if(*size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n",jobs[0].id);

    swap(&jobs[0],&jobs[(*size)-1]);

    (*size)--;

    minheapify(jobs,0,*size);
}

void next_job(job jobs[],int size)
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n",jobs[0].id);
}

void replace_priority(job jobs[],int id,int np,int size)
{
    int i = search(jobs,id,size);

    if(i == -1)
        printf("-1\n");
    else 
    {
        jobs[i].priority = np;
        if (i > 0 && jobs[(i-1)/2].priority > jobs[i].priority) {
            
            while(i > 0 && jobs[(i-1)/2].priority > jobs[i].priority) {
                swap(&jobs[i], &jobs[(i-1)/2]);
                i = (i-1)/2;
            }
        } else {
            minheapify(jobs, i, size);
        }
    }
}

void display(job jobs[],int size)
{
    if(size == 0)
        printf("-1\n");
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d %d\n",jobs[i].id,jobs[i].priority);
    }
}

int main()
{
    char c = 'A';
    job jobs[MAX];
    int size = 0;

    int n,p;

    while(c != 'g')
    {
        scanf(" %c",&c);

        switch(c)
        {
            case 'a':
                scanf("%d%d",&n,&p);
                Add(jobs,n,p,&size);
                break;
            case 'b':
                Schedule(jobs,&size);
                break;
            case 'c':
                next_job(jobs,size);
                break;
            case 'd':
                scanf("%d%d",&n,&p);
                replace_priority(jobs,n,p,size);
                break;
            case 'e':
                display(jobs,size);
                break;
            default:
                break;
        }
    }
    return 0;
}