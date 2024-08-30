#include<stdio.h>
#define MAX 100

typedef struct Queue{
    int front,rear;
    int items[MAX];
}queue;

int isEmpty(queue* Q)
{
    return Q->front == -1;
}

int isFull(queue* Q)
{
    return Q->rear == MAX-1;

}

void enqueue(queue* Q,int n)
{
    if(isFull(Q))
    {
        printf("Queue is full\n");
        return;
    }

    if(isEmpty(Q))
        Q->front = 0;
    
    Q->items[++(Q->rear)] = n;

}

int dequeue(queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int item = Q->items[Q->front];
    if(Q->front == Q->rear)
        Q->front = Q->rear = -1;
    else Q->front++;

    printf("Dequed\n");
    return item;
}

void display(queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = Q->front; i <= Q->rear; i++)
    {
        printf("%d ",Q->items[i]);    }
    
    printf("\n");
}

int Front(queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return Q->items[Q->front];

}

int Rear(queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return Q->items[Q->rear];

}



int main()
{
    char c = 'A';
    queue Q;
    Q.front = -1;
    Q.rear = -1;
    while(c != 'e')
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'i':
                int n;
                scanf("%d",&n);
                enqueue(&Q,n);
                break;
            case 'd' :
                dequeue(&Q);
                break;
            case 'p':
                display(&Q);
                break;
            case 'f':
                printf("%d\n",Front(&Q));
                break;
            case 'r':
                printf("%d\n",Rear(&Q));
                break;
            default:
                continue;

        }
    }    
}
