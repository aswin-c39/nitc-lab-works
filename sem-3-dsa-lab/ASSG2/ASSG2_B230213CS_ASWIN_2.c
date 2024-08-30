#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key,val,height;
    struct node *left,*right;
}node;


struct node* createnode(int key, int val)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->key = key;
    newnode->val = val;
    newnode->height = -1; 
    newnode-> left = newnode->right = NULL;
    return newnode;
}

int max(int l,int h)
{
    if(l>h)
        return l;
    return h;
}

int height(node* root)
{
    if (root == NULL)
        return -1;
    
    return root->height;
}

int balancefactor(node* root)
{
    return height(root->left) - height(root->right);
}

node* rightRotate(node* root)
{
    node* x = root->left;
    node* temp = x->right;

    x->right = root;
    root->left = temp;

    root->height = 1 + max(height(root->left),height(root->right));
    x->height = 1 + max(height(x->left),height(x->right));
    return x;
}

node* leftRotate(node* root)
{
    node* x = root->right;
    node* temp = x->left;

    x->left = root;
    root->right = temp;

    root->height = 1 + max(height(root->left),height(root->right));
    x->height = 1 + max(height(x->left),height(x->right));

    return x;
}

node* insert(node* root, int key, int val,int* count)
{
    if(root == NULL)
    {
        (*count)++;
        return createnode(key,val);
    }

    if(root->key > key)
        root->left = insert(root->left,key,val,count);
    else if(root->key < key)
        root->right = insert(root->right,key,val,count);
    else return createnode(key,val);
    
    root->height = 1 + max(height(root->left),height(root->right));

    int bal = balancefactor(root);

    if(bal > 1 && root->left->key > key)
        return rightRotate(root);
    

    if(bal < -1 && root->right->key < key) 
        return leftRotate(root);
    
    if(bal > 1 && root->left->key < key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if(bal < -1 && root->right->key > key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int find(node* root, int n)
{
    if(root == NULL)
    {
        printf("-1\n");
        return 0;
    }        
    if(root->key == n)
    {
        printf("%d %d\n",root->key,root->val);
        return 1;
    }

    if(n > root->key)
        find(root->right,n);
    if(n < root->key)
        find(root->left,n);
    return -1;
}

int search(node* root, int n)
{
    if(root == NULL)
    {
        return 0;
    }        
    if(root->key == n)
    {
        return 1;
    }

    if(n > root->key)
        search(root->right,n);
    if(n < root->key)
        search(root->left,n);
    return 0;
}

node* UpperBound(node* root,int key)
{
    node* upper = NULL;

    while(root != NULL)
    {
        if(key <= root->key)
        {
            upper = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return upper;
    
}

int empty(node* root)
{
    return root == NULL;
}

void display(node* root)
{
    if(root == NULL)
        return;
    display(root->right);
    printf("%d ", root->key);
    display(root->left);
}

int main()
{
    node* root = NULL;
    char c = 'A';
    node*x = NULL;
    int k,v,count = 0;
    while(c != 't')
    {
        scanf("%c", &c);
        
        switch(c)
        {
            case 'i':
                scanf("%d%d",&k,&v);
                root = insert(root,k,v,&count);
                break;
            case 'u':
                scanf("%d",&k);
                x = UpperBound(root,k);
                if(x == NULL)
                    printf("-1\n");
                else printf("%d %d\n",x->key,x->val);
                break;
            case 'f':
                scanf("%d",&k);
                find(root,k);
                break;
            case 's':
                printf("%d\n",count);
                break;
            case 'e':
                printf("%d\n",empty(root));
                break;
            case 'd':
                display(root);
                printf("\n");
                break;
            default:
                break;
        }
    }
    return 0;
}