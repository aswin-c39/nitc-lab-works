#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node* next;
    int flag;
}node;

struct node* createNode(int k){
	node* newnode = (node*)malloc(sizeof(node));
	
	newnode->key =  k;
	newnode->next = NULL;
    newnode->flag = 0;
	return newnode;
}


node* detectLoop(node* h)
{
    node* head = h;
    while(head != NULL)
    {
        if(head->flag)
            return head;

        head->flag = 1;
        head = head->next;
    }
    return NULL;
}

int main()
{
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head->next->next->next->next->next = head->next->next;

    node* loopnode = detectLoop(head);

    if(loopnode != NULL)
    {
        printf("Loop detected at %d\n",loopnode->key);
    }
    else{
        printf("No loop detected\n");
    }
    return 0;
}