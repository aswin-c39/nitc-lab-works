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
	node* head = NULL;
	if(h1->key > h2->key)
		head = h2;
	else
		head = h1;
	node *temp = head;
	while (temp != NULL)
	{
		if(temp=h1)
		{
			if(temp->next == NULL)
			{
				temp->next = h2;
				break;
			}
			if(h1->next->key > h2->key)
			{
				h1 = h1->next;
				temp->next = h2;
			}
			else
				h1 = h1->next;
		}
		
		if(temp=h2)
		{
			if(temp->next == NULL)
			{
				temp->next = h1;
				break;
			}
			if(h2->next->key > h1->key)
			{
				h2 = h2->next;
				temp->next = h1;
			}
			else
				h2 = h2->next;
		}
		temp = temp->next;
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
