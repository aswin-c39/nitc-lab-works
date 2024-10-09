#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int* heap,int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
}

void insert(int* heap, int* rear,int k)
{
    for(int i = 0 ; i < rear ; i++)
    {
        if(heap[i] == k)
            return;
    }
    
    heap[(*rear)++] = k;
    int i = *rear - 1;

    while(i > 0 && heap[(i-1)/2] < heap[i])
    {
        swap(&heap[i],&heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void maxheapify(int *heap,int k, int n)
{
    int largest = k;
    int left = 2*k + 1;
    int right = 2*k + 2;

    if(left < n && heap[left] > heap[largest])
        largest = left;
    if(right < n && heap[right] > heap[largest])
        largest = right;
    
    if(largest != k)
    {
        swap(&heap[largest], &heap[k]);
        maxheapify(heap,largest,n);
    }
}

int findmax(int* heap,int n)
{
    if(n == 0)
        return -1;
    return heap[0];
}

int extractmax(int *heap,int *n)
{
    if(n == 0)
        return -1;
    swap(&heap[0],&heap[*n - 1]);
    (*n)--;
    maxheapify(heap,0,*n);
    return heap[*n];
}

void delete(int *heap,int key,int *n)
{
    int i;
    int flag = 0;
    for(i = 0 ; i < *n ; i++)
    {
        if(heap[i] == key)
        {
            flag =1;
            break;
        }
    }
    if(flag)
    {
        heap[i] = heap[(*n)--];

        maxheapify(heap,i,*n);
        if(n == 0)
            printf("0\n");
        print(heap,*n);
    }
    else printf("-1\n");
}

void sort(int* arr,int size)
{
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

}

int kthlargest(int* heap,int k, int size)
{
    int *temp = (int*)malloc(size*sizeof(int));
    for(int i = 0 ; i < size ; i++)
    {
        temp[i] = heap[i];
    }
    
    sort(temp,size);

    
    int result = k <= size ? temp[k] : -1;
    return result; 
}

void replace(int *heap,int oldval,int newval,int n)
{
    int i,flag = 0;
    for(i = 0 ; i < n ; i++)
    {
        if(heap[i] == oldval)
        {
            flag = 1;
            break;
        }
    }
     if(flag) {
        heap[i] = newval;  

        if (i > 0 && heap[(i-1)/2] < heap[i]) {
            
            while(i > 0 && heap[(i-1)/2] < heap[i]) {
                swap(&heap[i], &heap[(i-1)/2]);
                i = (i-1)/2;
            }
        } else {
            maxheapify(heap, i, n);
        }
        print(heap, n);  
    }
    else printf("%d\n",abs(oldval - newval));
}

int main()
{
    char c = 'A';
    int n,m, rear = 0;
    int heap[MAX];
    while(c != 'g')
    {
        scanf("%c",&c);

        switch(c)
        {
            case 'a':
                scanf("%d",&n);
                insert(heap,&rear,n);
                break;
            case 'b':
                printf("%d\n",findmax(heap,rear));
                break;
            case 'c':
                printf("%d ",extractmax(heap,&rear));
                print(heap,rear);
                break;
            case 'd':
                scanf("%d",&n);
                printf("%d\n",kthlargest(heap,n,rear));
                break;
            case 'e':
                scanf("%d",&n);
                delete(heap,n,&rear);
                break;
            case 'f':
                scanf("%d%d",&n,&m);
                replace(heap,n,m,rear);
                break;
            default:
                break;
        }
    }
    return 0;
}