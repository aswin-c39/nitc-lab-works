#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Stack
{
    int items[MAX];
    int top;
}Stack;

typedef struct queue
{
    Stack *ip;
    Stack *op; 
}Q;

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* stack,int n)
{
    if(stack->top == MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    (stack->top)++;
    stack->items[stack->top] = n;
}

int pop(Stack* stack)
{
    if(stack->top == -1)
    {
        return -1;
    }
    return stack->items[(stack->top)--];
}



void enqueue(Q *q,int k)
{
    push(q->ip,k);
}

int dequeue(Q *q)
{
    if(isEmpty(q->op)){
        while(!isEmpty(q->ip)){
            int n = pop(q->ip);
            push(q->op,n);
        }
    }
    int deq = pop(q->op);
    if(deq == -1)
        printf("queue is empty\n");
    else printf("Dequeued\n");
    return deq;
}

void display(Q *q)
{
    
    for (int i = q->op->top; i >= 0; i--)
    {
        printf("%d ",q->op->items[i]);
    }
    for (int i = 0; i <= q->ip->top; i++)
    {
        printf("%d ",q->ip->items[i]);
    }
    printf("\n");
    
}

Q* createQueue() {
    Q* queue = (Q*)malloc(sizeof(Q));
    queue->ip = (Stack*)malloc(sizeof(Stack));
    queue->op = (Stack*)malloc(sizeof(Stack));
    queue->ip->top = -1;
    queue->op->top = -1;
    return queue;
}

int Front(Q *q)
{
    
    if(q->op->top == -1 )
    {
        if(q->ip->top == -1)
        {
            printf("Queue is empty\n");
            return -1;
        }
        else
            return q->ip->items[0];
    }

    return q->op->items[q->op->top];
}

int Rear(Q *q)
{
    if(q->ip->top == -1 )
    {
        if(q->op->top == -1)
        {
            printf("Queue is empty\n");
            return -1;
        }
        else
            return q->op->items[0];
    }

    return q->ip->items[q->ip->top];    


}

int main() {
    char c = 'A';
    Q *q = createQueue();

    while (c != 'e') {
        scanf(" %c", &c); 
        switch (c) {
            case 'i': {
                int n;
                scanf("%d", &n);
                enqueue(q, n);
                break;
            }
            case 'd':
                dequeue(q);
                break;
            case 'p':
                display(q);
                break;
            case 'f':
                printf("%d\n", Front(q));
                break;
            case 'r':
                printf("%d\n", Rear(q));
                break;
            default:
                continue;
        }
    }

    free(q->ip);
    free(q->op);
    free(q);

    return 0;
}