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

int SearchKey(node* root,int key)
{
    node* x=root;
    while(x!=NULL)
    {
        if(x->key==key)
            return 1;
        if(x->key>key)
            x=x->left;
        else    
            x=x->right;
    }
    
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

void Inorder(node* root) {
    if (root) {
        Inorder(root->left);
        printf("%d ", root->key);
        Inorder(root->right);
    }
}

void Preorder(node* root) {
    if (root) {
        printf("%d ", root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(node* root) {
    if (root) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->key);
    }
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
                if(SearchKey(root,key)==1)
                    printf("PRESENT\n");
                else    
                    printf("NOT PRESENT\n");
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
            
            case 'p':
            {
                Inorder(root);
                printf("\n");
                break;
            }

            case 't':
            {
                Preorder(root);
                printf("\n");
                break;
            }

            case 'b':
            {
                Postorder(root);
                printf("\n");
                break;
            }

            case 'e':
                break;

        }
    }


}