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

node* reverse(node* head)
{
	node *prevnode=NULL,*curnode=head,*nexnode=head;
	while(nexnode != NULL)
	{
		nexnode = nexnode->next;
		curnode->next = prevnode;
		prevnode = curnode;
		curnode = nexnode;
	}
	return prevnode;
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
	else if(c == 'r')
	{
		head=reverse(head);
	}
	else if(c == 'p')
	{
		display(head);
	}
	else if(c == 'e')
		break;
	else 
		continue;
	}
	return 0;
}
