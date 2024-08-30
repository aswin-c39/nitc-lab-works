#include<stdio.h>

#define MAX 1000 
typedef struct Stack {
    int items[MAX];
    int top;
} Stack;


void push(Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++(stack->top)] = value;
}


int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Empty\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int peek(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Empty\n");
        return -1;
    }
    return stack->items[stack->top];
}

void nextGreaterElement(int arr[], int n)
{
    Stack s;
    s.top = -1;
    
    push(&s,arr[0]);

    for (int i = 1; i < n; i++)
    {
        int next = arr[i];
        int element;
        if(isEmpty(&s) == 0)
        {
            element = pop(&s);
            while (element < next)
            {
                printf("%d ",next);
                if(isEmpty(&s) == 1)
                    break;
                element = pop(&s);
            }
            
            if(element > next)
                push(&s, element);
        }    
        
        push(&s, next);

    }
     while(isEmpty(&s) != 1)
     {
        pop(&s);
        printf("-1 ") ;
    }
    printf("\n");   
}


int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    nextGreaterElement(arr,n);

    return 0;
}