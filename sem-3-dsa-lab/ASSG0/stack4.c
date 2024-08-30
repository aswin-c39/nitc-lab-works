#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

typedef struct {
    int top;
    int items[100];
} Stack;

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

void display(Stack* stack)
{
    if(stack->top == -1)
    {
        printf("Stack Empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++)
    {
        if(stack->items[i] == -1)
            printf(" ");
        else printf("%d",stack->items[i]);
    }
    
    

}

void infixToPostfix(char* exp)
{
    Stack s;
    s.top = -1;
    char op;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(isdigit(exp[i]))
        {
            int num = exp[i] - '0';
            push(&s,num);
        }
        else{
            if(exp[i] == ' ')
            {
                push(&s,-1);
                continue;
            }
            else{
                push(&s,-1);
                op = exp[i];
            }
        }
    }
    display(&s);
    printf(" %c\n",op);
}

int main()
{
    char exp[100];
    printf("Enter a infix expression: ");
    fgets(exp,100,stdin);
    
    size_t len = strlen(exp);
    if (len > 0 && exp[len - 1] == '\n') {
        exp[len - 1] = '\0';
    }

    printf("Result : ");
    infixToPostfix(exp);
    return 0;
}

