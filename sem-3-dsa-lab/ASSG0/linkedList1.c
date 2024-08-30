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

node* delete(node* head,int k)
{
	if(head == NULL)
		return NULL;
	node* temp = head;
	while(temp->next->key != k)
	{
		temp = temp->next;
	}
	node* dnode = temp->next;
	temp->next = temp->next->next;
	free(dnode);
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
	else if(c == 'd')
	{
		int num;
		scanf("%d",&num);
		head=delete(head,num);
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
