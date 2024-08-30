#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[50];
    char num[15];
    char time[5];
    struct node *next;
    struct node *prev;
}node;

node* create_node(char name[],char num[],char time[])
{
    node *newnode=(node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE); 
    }
    strcpy(newnode->name,name);
    strcpy(newnode->num,num);
    strcpy(newnode->time,time);
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void insert_node(node **head,node **tail,char name[],char num[],char time[])
{
    node *newnode=create_node(name,num,time),*temp;

    if(*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
    }

    else
    {

        (*tail)->next=newnode;
        newnode->prev=*tail;
        *tail=newnode;
    }

}

char* input()
{
    
    char c;
    char* A=(char*)malloc(sizeof(char));
    if (A == NULL) {
        printf("Memory allocation failed\n");
        exit(0); 
    }
    int i=0;
    while((c=getchar())!='\n')
    {
         if (A == NULL) {
            printf("Memory allocation failed\n");
            free(A);
            exit(EXIT_FAILURE); 
        }
        A=(char*)realloc(A,(i+1)*sizeof(char));
        A[i++]=c;
    }
    A[i]='\0';
    return A;
}

void del_node(node *x,node **head,node **tail)
{
    if(((*head)->next)==NULL)
    {
        *head=NULL;
        *tail=NULL;
    }
    else{
        if(x==*head)
        {
            *head=x->next;
            (*head)->prev=NULL;
        }
        else if(x==*tail)
        {
            *tail=x->prev;
            (*tail)->next=NULL;
        }
        else{
        x->prev->next=x->next;
        x->next->prev=x->prev;
        }
    }
    free(x);
}

void print(node *head)
{
    node *x;
    x=head;
    if(x==NULL)
    {
        printf("\nReservation Queue is empty\n");
    }
    else
    {
        while(x!=NULL)
        {
            printf("%s (%s)\n",x->name,x->time);
            x=x->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice=1;

    node *head=NULL,*tail=NULL;

    while(choice!=5)
    {
        printf("\nMenu:\n");
        printf("1. Add Reservation\n2. View Next Booking Request\n");
        printf("3. Cancel Reservation\n4. Display Reservation Queue\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            char *name,*num,*time;
            getchar();
            
            printf("1. Customer Name: ");
            name=input();

            printf("2.Phone Number: ");
            num=input();

            printf("3.Arrival Time: ");
            time=input();

            insert_node(&head,&tail,name,num,time);
            printf("\n");
            printf("Reservation added successfully for %s\n",name);
            free(name);
            free(num);
            free(time);
          
        }

        if(choice==2)
        {
            getchar();
            printf("\n");
            printf("\nNext Booking Request: ");
            if(head!=NULL)
            {
                printf("%s (%s)\n",head->name,head->time);
            }
            else
                printf("\nNo booking request available\n");

        }

        if(choice==3)
        {
            getchar();
            char *name;
            printf("Reservation to cancel: ");
            name=input();

            node*x=head;

            while(x!=NULL)
            {
                if((strcmp(x->name,name))==0)
                {
                    break;
                }
                else
                    x=x->next;
            }
            
            if(x==NULL)
                printf("\nReservation for %s does not exist\n",name);
            else
            {
               del_node(x,&head,&tail);
               printf("\nReservation for %s canceled successfully\n",name);
            }
            free(name);
        }
        if(choice==4)
        {
            getchar();
            print(head);
        }
    }
    
    printf("\nExiting...\n");
    node *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}