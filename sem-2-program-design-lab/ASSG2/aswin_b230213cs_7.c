#include<stdio.h.>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char url[50];
    struct node* next;
}node;

typedef struct stack
{
    node *top;
}stack;

void Visit_New_Page(stack* stack,char* url)
{
    node *newnode=(node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }
    strcpy(newnode->url,url);
    newnode->next=stack->top;
    stack->top=newnode;
}

char* Go_Back(stack *stack)
{
    if(stack->top == NULL)
    {
        printf("\nstack is underflow\n");
        return NULL;
    }
    node *temp=stack->top;
    stack->top= stack->top->next;
    char* url=(char*)malloc(sizeof(char)*50);
    strcpy(url,temp->url);
    free(temp);
    return url;
}

int isempty(stack *stack)
{
    return stack->top==NULL;
}

void Clear_History(stack *stack)
{
    while(!isempty(stack))
    {
        Go_Back(stack);
    }
}

void Display_History(stack *stack)
{
    node *x=stack->top;
    printf("\nBrowsing History:\n");
    while(x!=NULL)
    {
        printf("%s\n",x->url);
        x=x->next;
    }
}

int main()
{
    int choice=1;
    char url[50];
    node *head=NULL;
    stack stack;

    while(choice!=5)
    {
        printf("\nMenu:\n");
        printf("1. Visit New Page\n2. Go Back\n");
        printf("3. Clear History\n4. Display History\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter url: ");
                scanf("%s",url);
                Visit_New_Page(&stack,url);
                printf("\nPage '%s' visited successfully.\n",url);
                break;

            case 2:
            if(!isempty(&stack))
            {
                char *x=Go_Back(&stack);
                printf("\nNavigating back to page '%s'\n",x);
                free(x);
            }
            else{
                printf("\nNo more pages to go back to.\n");
            }
                break;

            case 3:
                Clear_History(&stack);
                printf("\nHistory Cleared.\n");
                break;
            
            case 4:
                if(isempty(&stack))
                    printf("\nNo History.\n");
                else
                    Display_History(&stack);
                break;
            
            case 5:
                printf("\nExiting...\n");
                Clear_History(&stack);
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}