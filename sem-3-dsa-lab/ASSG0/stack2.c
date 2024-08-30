#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node* next;
    struct node* prev;
}node;

typedef struct Stack{
    node* top;
}Stack;

struct node* createnode(int k){
	node* newnode = (node*)malloc(sizeof(node));
	
	newnode->key =  k;
	newnode->next = NULL;
    newnode->prev = NULL;
	return newnode;
}

void push(Stack* stack,int n)
{
    if(stack->top == NULL)
    {
        stack->top = createnode(n);
        return;
    }
    stack->top->next = createnode(n);
    stack->top->next->prev = stack->top;
    stack->top = stack->top->next;
}

int pop(Stack* stack)
{
    if(stack->top == NULL)
    {
        printf("Stack Empty\n");
        return -1;
    }
    int t = stack->top->key;
    node* temp = stack->top;
    stack->top = stack->top->prev;
    free(temp);
    return t;
}

int peek(Stack* stack)
{
    if(stack->top == NULL)
    {
        printf("Stack Empty\n");
        return -1;
    }
    return stack->top->key;
}

void display(Stack* stack)
{
    node* temp = stack->top;
    printf("Contents : ");
    while(temp != NULL)
    {
        printf("%d, ",temp->key);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    Stack stack;
    stack.top = NULL;
    char c;

    while (scanf(" %c", &c) != EOF) 
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
            printf("%d\n",peek(&stack));
            break;
        case 'p':
            display(&stack);
            break;
        default:
            continue;
    }
    }
    return 0;
}
