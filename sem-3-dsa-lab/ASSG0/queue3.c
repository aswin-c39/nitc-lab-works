#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

typedef struct Stack {
    Queue q1;
    Queue q2;
} Stack;

int isEmptyQ(Queue* q){
    return q->front == -1;
}

int isFullQ(Queue* q){
    return q->rear == MAX-1;
}

void enqueue(Queue* q, int n){
    if(isFullQ(q))
    {
        printf("Queue is full\n");
        return;
    }
    if(isEmptyQ(q))
        q->front = 0;
    q->items[++(q->rear)] = n;
}

int dequeue(Queue* q){
    if(isEmptyQ(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int item = q->items[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else q->front++;

    return item;
}


void push(Stack* stack, int n){
    enqueue(&stack->q2, n);

    while (!isEmptyQ(&stack->q1)){
        int k = dequeue(&stack->q1);
        enqueue(&stack->q2, k);
    }

    Queue temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

int pop(Stack* stack){
    int pop = dequeue(&stack->q1);
    if(pop != -1)
        printf("popped\n");
    return pop;
}

int top(Stack *stack)
{
    if(isEmptyQ(&stack->q1))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->q1.items[stack->q1.front];
}

void display(Stack* stack){
    if(isEmptyQ(&stack->q1))
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->q1.front; i <= stack->q1.rear; i++)
    {
        printf("%d ",stack->q1.items[i]);
    }
    printf("\n");
}

int main(){
    Stack stack;
    stack.q1.front = -1;
    stack.q1.rear = -1;
    stack.q2.front = -1;
    stack.q2.rear = -1;

    char c;

    while (scanf(" %c", &c) != 'e') 
    {
        switch(c){
        case 'i':
            int n;
            scanf("%d",&n);
            push(&stack,n);
            break;
        case 'd':
            printf("%d\n",pop(&stack));
            break;
        case 'c':
            printf("%d\n",top(&stack));
            break;
        case 'p':
            display(&stack);
            break;
        default:
            continue;
    }
    }
}
