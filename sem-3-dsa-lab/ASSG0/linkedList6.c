#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node* next;
	
}node;

struct node* createnode(int k){
	node* newnode = (node*)malloc(sizeof(node));
	
	newnode->key =  k;
	newnode->next = NULL;
	return newnode;
}

node* insert(node* head,int k)
{
	if(head==NULL)
	{
		return createnode(k);
	}
	
	node* nnode = head;
	
	while (nnode->next != NULL)
	{
		nnode = nnode->next;
	}
	
	nnode->next = createnode(k);
	return head;
}

void display(node* head)
{
	node* temp=head;
	while(temp != NULL)
	{
		printf("%d ",temp->key);
		temp=temp->next;
	}
	printf("\n");
}

node* reverseKnodes(node* head,int k)
{
    if(head == NULL || k <= 1) 
        return head;
    node *prev = NULL,*cur = head,*next = NULL;
    node *newHead = NULL, *tail = NULL;

    int count = 0;

    int len = 0;
    while(cur != NULL)
    {
        len++;
        cur = cur->next;
    } 
    cur = head;

    while(len>=k)
    {
        node* ghead = cur;
        prev = NULL;
        count = 0;
        while(count < k && cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count++;
        }
        if(newHead == NULL) 
            newHead = prev;
        
        if(tail != NULL)
            tail->next = prev;
        
        tail = ghead;
        len -= k;
    }
    prev = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    if(newHead == NULL) 
            newHead = prev;
        
    if(tail != NULL)
        tail->next = prev;
        
    

    return newHead;
}

int main()
{
	node* head = NULL;
	while(1)
	{
	
	char c;
	scanf("%c",&c);
	
	if(c == 'i')
	{
		int num;
		scanf("%d",&num);
		head=insert(head,num);
	}
    else if(c == 'p')
	{
		display(head);
	}
    else if(c == 'r')
    {
        int k;
		scanf("%d",&k);
		head=reverseKnodes(head,k);
        display(head);
    }
	else if(c == 'e')
		break;
	else 
		continue;
	}
	return 0;
}