#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int mod;
    char* name;
	int price;
	struct node* left;
    struct node* right;
    struct node* parent;
	
}node;

node* Create_Node(int mod_n,char* str,int price){
	node* newnode = (node*)malloc(sizeof(node));
	
	newnode->mod = mod_n;
    newnode->name = (char*)malloc(strlen(str)+1);
    strcpy(newnode->name,str);
    newnode->price = price;
	newnode->right = NULL;
    newnode->left = NULL;
    newnode->parent = NULL;
	return newnode;
}

node* Add(node* T,node* x){
    if(T == NULL)
        return x;

    node* temp = T;
    while(temp != NULL)
    {
        if(x->mod < temp->mod)
        {
            if(temp->left == NULL)
            {
                temp->left = x;
                x->parent = temp;
                return T;
            }
            temp = temp->left;
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right = x;
                x->parent = temp;
                return T;
            }
            temp = temp->right;
        }
    }
    return T;
    
}

node* Delete(node* T,node* x)
{
    if(x == NULL)
        return T;
    if(x->left == NULL && x->right == NULL)
    {
        if(x == T)
            T = NULL;
        else if(x->parent->left == x)
            x->parent->left = NULL;
        else
            x->parent->right = NULL;
    }
    else if(x->left == NULL || x->right == NULL)
    {
        node* child;
        if(x->left == NULL)
            child = x->right;
        else child = x->left;

        if(x == T)
            T = child;
        else if(x->parent->left == x)
            x->parent->left = child;
        else
            x->parent->right = child;
        
        child->parent = x->parent;
    }
    else {
        node* suc = x->right;
        while(suc->left != NULL)
            suc = suc->left;
        x->mod = suc->mod;
        free(x->name);
        x->name = (char*)malloc(strlen(suc->name)+1);
        strcpy(x->name,suc->name);
        x->price = suc->price;
        return Delete(T, suc);
    }
    free(x->name);
    free(x);
    return T;
}

node* Search(node* T,int mod)
{
    if(T == NULL)
        return NULL;

    if(T->mod == mod)
        return T;

    if(mod < T->mod)
        return Search(T->left,mod);
    else
        return Search(T->right,mod);
}

void Inorder(node* T)
{
    if(T == NULL)
        return;
    Inorder(T->left);
    printf("%d %s %d\n",T->mod,T->name,T->price);
    Inorder(T->right);
}

void Preorder(node* T)
{
    if(T == NULL)
        return;
    printf("%d %s %d\n",T->mod,T->name,T->price);
    Preorder(T->left);
    Preorder(T->right);
}

void Postorder(node* T)
{
    if(T == NULL)
        return;
    Postorder(T->left);
    Postorder(T->right);
    printf("%d %s %d\n",T->mod,T->name,T->price);
}

node* Modify(node* T,int mod,int new_price)
{
    node* temp = Search(T,mod);
    if(temp == NULL)
        return T;
    temp->price = new_price;
    printf("%d %s %d\n",temp->mod,temp->name,temp->price);
    return T;
}

int main()
{
    node* T = NULL;
    char c = 'A';
    int n,p;
    char s[20];
    node* x;
    while(c != 'e')
    {
        scanf(" %c",&c);

        switch(c)
        {
            case 'a':
                char s[20];
                scanf("%d%s%d",&n,s,&p);
                x = Create_Node(n,s,p);
                T = Add(T,x);
                break;
            case 'd':
                scanf("%d",&n);
                x = Search(T,n);
                if(x != NULL)
                    printf("%d %s %d\n",x->mod,x->name,x->price);
                T = Delete(T,x);
                break;
            case 's':
                scanf("%d",&n);
                x = Search(T,n);
                if(x == NULL)
                    printf("-1\n");
                else
                    printf("%d %s %d\n",x->mod,x->name,x->price);
                break;
            case 'i':
                Inorder(T);
                break;
            case 'p':
                Preorder(T);
                break;
            case 't':
                Postorder(T);
                break;
            case 'm':
                scanf("%d%d",&n,&p);
                Modify(T,n,p);
                break;
        }
    }
    return 0;
}