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


int postfix(char* exp)
{
    Stack s;
    s.top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(isdigit(exp[i]))
        {
            
            int num = 0;
            
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            push(&s,num);

            
        }
        else if(exp[i] == ' ')
            continue;
        else{
            int val2 = pop(&s);
            int val1 = pop(&s);

            switch(exp[i])
            {
                case '+':
                    push(&s,val1+val2);
                    break;
                case '-':
                    push(&s,val1-val2);
                    break;
                case '*':
                    push(&s,val1*val2);
                    break;
                case '/':
                    if(val2 == 0)
                    {
                        printf("Cannot divide by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&s,val1/val2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
            }   
        }
        return pop(&s);  
} 

int main()
{
    char exp[100];
    printf("Enter a postfix expression: ");
    fgets(exp,100,stdin);
    
    size_t len = strlen(exp);
    if (len > 0 && exp[len - 1] == '\n') {
        exp[len - 1] = '\0';
    }

    printf("Result : %d", postfix(exp));
    return 0;
}

