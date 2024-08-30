#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
}node;

node* create_node(int k)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->key=k;
    newnode->next=NULL;
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
    }
}

void sort(node *head)
{
    node *x=head;
    while(x->next!=NULL)
    {
        node *min=x,*y=x->next;
        while(y!=0)
        {
            if((y->key)<(min->key))
            {
                min=y;
            }
            y=y->next;
        }
        int temp=x->key;
        x->key=min->key;
        min->key=temp;
        x=x->next;
    }

}

void print(node *head)
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

int main()
{
    char c='i';
    int k;
    
    node *head=NULL;
    while(c!='e')
    {
        scanf("%c",&c);
        if(c=='i')
        {
            scanf("%d",&k);
            insert_node(&head,k);
        }

        if(c=='p')
        {
            print(head);
        }

        if(c=='s')
        {
            sort(head);
        }
    }

    return 0;
    
}