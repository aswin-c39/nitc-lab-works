#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}node;

node* createnode(int k)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->key = k;
    newnode->next = NULL;
    return newnode;
}

int search(node* head,int key)
{
    int pos = 1;
    while(head != NULL)
    {
        if(head->key == key)
        {
            return pos;
        }

        head = head->next;
        pos++;
    }
    return -1;
}

node* insert(node* head,int key)
{
    if(search(head,key) != -1)
    {
        printf("-1\n");
        return head;
    }
    if(head == NULL)
    {
        return createnode(key);
    }
    else if(head->key > key)
    {
        node* newnode = createnode(key);
        newnode->next = head;
        return newnode;
    }
    else
        head->next = insert(head->next,key);

    return head;
}

node* delete(node* head,int key,int ind)
{
    node* cur = head,*prev = NULL;
    int s = search(head,key);
    if(s != -1)
    {
        while(cur != NULL)
        {
            
            if(cur->key == key)
            {
                if(cur == head)
                    head = cur->next;
                else prev->next = cur->next;
                printf("%d %d\n",ind,s);
                break;
            }

            prev = cur;
            cur = cur->next;
        }
        free(cur);
    }
    else printf("-1\n");

    return head;
}

void update(node* H[],int oldkey,int newkey,int N)
{  
    int h1 = oldkey % N, h2 = newkey % N;   
    if(search(H[h1],oldkey) == -1)
    {
        printf("-1\n");
        return;
    }
    if(search(H[h2],newkey) != -1)
    {
        printf("-1\n");
        return;
    }

    H[h1] = delete(H[h1],oldkey,h1);
    H[h2] = insert(H[h2],newkey);

    return;

}

void printelements(node* head)
{
    if(head == NULL)
    {
        printf("-1\n");
        return;
    }

    while(head != NULL)
    {
        printf("%d ",head->key);
        head = head->next;
    }

    return;
}

int main()
{
    int N;
    scanf("%d",&N);
    node* H[N];
    for(int i = 0 ; i < N ; i++)
    {
        H[i] = NULL;
    }

    char c = 'A';

    int key,ind;
    node* head;
    
    int s;
    while(c != 'f')
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'a':  
                scanf("%d",&key);
                ind = key % N;
                H[ind] = insert(H[ind],key);
                break;
            case 'b':
                scanf("%d",&key);
                ind = key % N;
                s = search(H[ind],key);
                if(s != -1)
                    printf("%d %d\n",ind,s);
                else printf("-1\n");
                break;
            case 'c':
                scanf("%d",&key);
                ind = key % N;
                H[ind] = delete(H[ind],key,ind);
                break;
            case 'd':
                scanf("%d%d",&key,&s);
                update(H,key,s,N);
                break;
            case 'e':
                scanf("%d",&ind);
                printelements(H[ind]);
                printf("\n");
                break;
            case 'f':
                break;
        }
    }
    return 0;
}
