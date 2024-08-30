#include<stdio.h>
#define MAX 100
struct Stack
{
    int A[MAX];
    int top;
};

void push(struct Stack* stack,int n)
{
    if(stack->top == MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    (stack->top)++;
    stack->A[stack->top] = n;
}

int pop(struct Stack* stack)
{
    if(stack->top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    return stack->A[(stack->top)--];
}

int peek(struct Stack stack)
{
    if(stack.top == -1)
    {
        printf("Stack Empty\n");
    }
    return stack.A[stack.top];
}

void display(struct Stack* stack)
{
    if(stack->top == -1)
    {
        printf("Stack Empty\n");
        return;
    }
    printf("Contents :\n");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d\n",stack->A[i]);
    }
    

}

int main()
{
    struct Stack stack;
    stack.top = -1;
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
            printf("%d\n",peek(stack));
            break;
        case 'p':
            display(&stack);
            break;
        default:
            continue;
    }
    }
}