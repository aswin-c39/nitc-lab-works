#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
    struct node *prev;
}node;

node* create_node(int k)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->key=k;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void insert_node(node **head,int k)
{
    node *x=create_node(k),*temp;

    if(*head==NULL)
    {
        *head=x;

    }

    else
    {
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=x;
        x->prev=temp;
    }
}

void initial_list(node *head)
{
    node *x;
    x=head;

    while(x!=NULL)
    {
        printf("%d ",x->key);
        x=x->next;
    }
    printf("\n");
}

void reverse_list(node **head)
{
    node *current=*head,*temp=NULL;
    while(current!=NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;   
    }
    if(temp != NULL)
        *head = temp->prev;
}

int main()
{
    char c='i';
    int k;

    node *head=NULL;

    while (c!='e')
    {
        scanf("%c",&c);

        if(c=='i')
        {
            scanf("%d",&k);
            insert_node(&head,k);
        }

        if(c=='p')
        {
            initial_list(head);
        }

        if(c=='r')
        {
            reverse_list(&head);
        }

    }
    node *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    
    
}