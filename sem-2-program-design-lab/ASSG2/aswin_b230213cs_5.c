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
        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        temp->next=x;
    }
    x->next=*head;
}

void print(node *head)
{
    node *x;
    x=head;

    while(x->next!=head)
    {
        printf("%d ",x->key);
        x=x->next;
    }

    printf("%d\n",x->key);
}

int NGE(node *p)
{
    node *temp=p->next;
    do
    {
        
        if(temp->key > p->key)
        {
            return(temp->key);
        }
        temp=temp->next;
    
    }while(temp!=p);
    return -1;

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

        if(c=='g')
        {
            scanf("%d",&k);
            node *x=head;
            do{
                if(x->key==k)
                {
                    printf("%d\n",NGE(x));
                    break;
                }
                
                x=x->next;
            
            }while(x!=head);
        }
    }
    node *x=head,*temp;
    do
    {
        temp=x;
        x=x->next;
        free(temp);
    }while(x!=head);
    return 0;
}