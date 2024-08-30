
#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int key;
    struct node *left;
    struct node *right;
}node;


node* createnode(int key)
{
    node* newnode=(node*) malloc(sizeof(node));
    newnode->key=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void kthsmallestutil(node* root,int k,int*count,int* kthsmallest)
{
    if(root==NULL || *count>=k)
        return;
    kthsmallestutil(root->left,k,count,kthsmallest);
    (*count)++;
    if(*count==k)
    {
        *kthsmallest=root->key;
        return;
    }

    kthsmallestutil(root->right,k,count,kthsmallest);

}

int KthSmallest(node* root,int k)
{
    int count=0,kthsmallest=1;
    kthsmallestutil(root,k,&count,&kthsmallest);
    return kthsmallest;
}
node* InsertKey(node* root,int key)
{
    if(root==NULL)
    {
        root=createnode(key);
    }
    else if(root->key>=key)
    {
        root->left=InsertKey(root->left,key);
    }
    else
    {
        root->right=InsertKey(root->right,key);
    }
    return root;
}

void maximum(node* root)
{
    node* x=root;
    while (x->right!=NULL)
    {
        x=x->right;
    }
    printf("%d\n",x->key);
    
}

node* SearchKey(node* root,int key)
{
    node* x=root;
    while(x!=NULL)
    {
        if(x->key==key)
            return x;
        if(x->key>key)
            x=x->left;
        else    
            x=x->right;
    }
    
}

node* leftmost(node* root)
{
    if(root==NULL)
        return NULL;
    while (root->left!=NULL)
        root=root->left;
    
    return root;
}

void successor(node* root,int n)
{
    node* target=SearchKey(root,n);
    node* successor=NULL;
    if(target==NULL)
        return;

    if(target->right!=NULL)
    {
        successor=leftmost(target->right);
    }
    else{
        node* current=root;
        while(current!=NULL)
        {
            if(target->key<current->key)
            {
                successor=current;
                current=current->left;
            }
            else if(target->key>current->key)
            {
                current=current->right;
            }
            else
                break;
        }
        
    }
    printf("%d\n",successor->key);


}

node* FindMin(node* Node)
{
    node* current=Node;
    while(current && current->left!=NULL)
        current=current->left;
    
    return current;
}

node* Deletekey(node* root,int key)
{
    if(root==NULL)
        return root;
    if(key<root->key)
        root->left=Deletekey(root->left,key);
    else if(key>root->key)
        root->right=Deletekey(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            node* temp=root->right;
            free(root);
            return temp;
        }

        else if(root->right==NULL)
        {
            node* temp=root->left;
            free(root);
            return temp;
        }
        node* temp=FindMin(root->right);
        root->key=temp->key;
        root->right=Deletekey(root->right,temp->key);
    }
    return  root;
}



int main()
{
    char choice='A';
    node* root=NULL;

    while(choice!='e')
    {
        scanf("%c",&choice);
        switch (choice)
        {
            case 'i':
            {
                int n;
                scanf("%d",&n);
                root=InsertKey(root,n);
                break;
            }

            case 's':
            {
                int key;
                scanf("%d",&key);
                if(SearchKey(root,key)==NULL)
                    printf("NOT PRESENT\n");
                else    
                    printf("PRESENT\n");
                break;
            }

            case 'd':
            {
                int key;
                scanf("%d",&key);
                if(SearchKey(root,key)==0)
                    printf("NOT PRESENT in the BST\n");
                else
                    root=Deletekey(root,key);
                break;
            }
            
            case 'k':
            {
                int k;
                scanf("%d",&k);
                printf("%d\n",KthSmallest(root,k));
                break;
            }

            case 'm':
            {
                maximum(root);
                break;
            }

            case 'n':
            {
                int n;
                scanf("%d",&n);
                successor(root,n);
                break;
            }

            case 'e':
                break;

        }
    }

}