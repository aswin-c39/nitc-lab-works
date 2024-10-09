#include<stdio.h>
#include<string.h>
#define MAX 1000

typedef struct patient{
    int id;
    char name[20];
    int priority;
}patient;

void swap(patient *a, patient *b)
{
    patient temp = *a;
    *a = *b;
    *b = temp;
}

void display(patient P[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",P[i].id);
    }
    printf("\n");
}

int querrypatient(patient P[], int id,int size)
{

    for(int i = 0 ; i < size ; i++)
    {
        if(P[i].id == id)
        {
            return i;
        }
    }

    return -1;

}

void admitPatient(patient P[], int id, char *name, int severity,int *size)
{
    patient p;
    p.id = id;
    strcpy(p.name,name);
    p.priority = severity;

    P[*size] = p;

    int i = (*size)++;

    while(i > 0 && P[i].priority < P[(i-1)/2].priority)
    {
        swap(&P[i],&P[(i-1)/2]);
        i = (i-1)/2;
    }

    display(P,*size);
}

void minheapify(patient P[],int i,int size)
{
    int min = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && P[left].priority < P[min].priority)
        min = left;
    
    if(right < size && P[right].priority < P[min].priority)
        min = right;

    if(min != i)
    {
        swap(&P[i],&P[min]);
        minheapify(P,min,size);
    }
}

void update(patient P[],int id,int new_p,int size)
{
    int i = querrypatient(P,id,size);
    //printf("%d",i);
    if(i != -1)
    {
        P[i].priority = new_p;
        if(i > 0 && P[i].priority < P[(i-1)/2].priority)
        {
            while(i > 0 && P[i].priority < P[(i-1)/2].priority)
            {
                swap(&P[i],&P[(i-1)/2]);
                i = (i-1)/2;
            }
        }
        else minheapify(P,i,size);
        display(P,size);
    }
    else printf("-1\n");
}

void treatPatient(patient P[],int *size)
{
    if(*size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d %s\n",P[0].id, P[0].name);

    P[0] = P[(*size)-1];
    (*size)--;

    minheapify(P,0,*size);
}

void heap_sort(patient arr[], int size)
{
    for(int i = size - 1 ; i >= 0 ; i--)
    {
        swap(&arr[0],&arr[i]);
        minheapify(arr,0,i);
    }
}

int findMostSevere(patient P[],int *size)
{
    if(size == 0)
    {
        printf("-1\n");
        return 0;
    }
    
    patient arr[*size];

    for(int i = 0 ; i < *size ; i++)
    {
        arr[i] = P[i];
    }

    heap_sort(arr,*size);

    for(int i = *size - 1 ; i > 0 ; i--)
    {
        printf("%d %s %d\n",arr[i].id,arr[i].name,arr[i].priority);
        if(i == *size - 3)
            break;
    }
}

int main()
{
    char c = 'A';
    int id,p,size = 0;
    char name[20];

    patient P[MAX];

    while(c != 'g')
    {
        scanf("%c",&c);

        switch(c)
        {
            case 'a':
                scanf("%d%d%s",&id,&p,name);
                admitPatient(P,id,name,p,&size);
                break;
            case 'b':
                treatPatient(P,&size);
                break;
            case 'c':
                scanf("%d%d",&id,&p);
                update(P,id,p,size);
                break;
            case 'd':
                scanf("%d",&id);
                p = querrypatient(P,id,size);
                if(p >= 0)
                    printf("%s %d\n",P[p].name,P[p].priority);
                else printf("-1\n");
                break;
            case 'e':
                findMostSevere(P,&size);
                break;
            default:
                break;
        }
    }
    
}