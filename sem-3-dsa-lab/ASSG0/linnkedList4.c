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

node* merge(node* h1,node*h2)
{
	node* head = h1;
	node* temp = h1;
	
	while(temp != NULL)
	{
		if(temp = h1)
		{
			h1 = h1->next;
			temp->next = h2;
		}
		if(temp = h2)
		{
			h2 = h2->next;
			temp->next = h1;
		}
		temp = temp->next;
		if(h1 == NULL || h2 == NULL)
			break;
		
	}
	return head;
}

int main()
{
	node *head1 = NULL, *head2 = NULL;
	
	head1=insert(head1,1);
	head1=insert(head1,3);
	head1=insert(head1,5);
	head1=insert(head1,7);
	
	head2=insert(head2,2);
	head2=insert(head2,4);
	head2=insert(head2,6);
	head2=insert(head2,8);
	
	node* head = merge(head1,head2);
	display(head);
	return 0;
	
}
