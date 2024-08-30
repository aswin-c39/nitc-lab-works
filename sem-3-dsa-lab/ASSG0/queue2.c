#include<stdio.h>

#include<stdlib.h>

typedef struct node{
	int key;
	struct node* next;
	
}node;

typedef struct Queue{
    node *front,*rear;
}queue;

int isEmpty(queue* q)

{
    return q->front == NULL;
}

struct node* createnode(int k){
	node* newnode = (node*)malloc(sizeof(node));
	
	newnode->key =  k;
	newnode->next = NULL;
	return newnode;
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



void enqueue(queue* q,int n)
{
    if(isEmpty(q))
    {
        q->front = createnode(n);
        q->rear = q->front;
        return;

    }
    q->rear->next = createnode(n);
    q->rear = q->rear->next;

}

int dequeue(queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
		
	node* dnode = q->front;
    int temp = dnode->key;
	q->front = q->front->next;
	free(dnode);
	return temp;
}

int main()
{
    char c = 'A';
    queue q;
    q.front = NULL;
    q.rear = NULL;

    while(c != 'e')
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'i':
                int n;
                scanf("%d",&n);
                enqueue(&q,n);
                break;
            case 'd' :
                dequeue(&q);
                break;
            case 'p':
                display(q.front);
                break;
            case 'f':
                printf("%d\n",q.front->key);
                break;
            case 'r':
                printf("%d\n",q.rear->key);
                break;
            default:
                continue;

        }
    }  
}
