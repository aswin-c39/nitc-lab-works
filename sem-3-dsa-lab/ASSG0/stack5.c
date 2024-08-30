#include<stdio.h>
#include<stdlib.h>

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

void nextGreaterfreq(int* arr,int n)
{
    int freq[MAX] = {0};
    Stack stack;
    stack.top = -1;
    

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int op[n];
    

    for (int i = 0; i < n; i++)
    {
        op[i] = -1;
    }


    for (int i = 0; i < n; i++)
    {
        while(!isEmpty(&stack) && freq[arr[peek(&stack)]] < freq[arr[i]])
        {
            op[pop(&stack)] = arr[i];
        }
        push(&stack,i);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ",op[i]);
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

    nextGreaterfreq(arr,n);

    return 0;
}
