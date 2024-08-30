#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* right, *left;
    int height;
}node;

typedef struct tree{
    struct node* root;
    int leftrot;
    int rightrot;
}tree;

node* createnode(int k)
{
    node* newnode = (node*)malloc(sizeof(node));

    newnode->data = k;
    newnode->left = newnode->right = NULL;
    newnode->height = 0;
    return newnode;
}

int max(int l, int h)
{
    if(l>h)
        return l;
    else return h;
}

int height(node* root)
{
    if(root == NULL)
        return -1;
    return root->height;
}

int balancefactor(node* root)
{
    if(root == NULL)
        return 0;
     return height(root->left) - height(root->right);
}

int AVL_balanceFactor(node* root, int n)
{
    node* temp = root;
    while(temp->data != n && temp != NULL)
   {
        if(n > temp->data)
            temp = temp->right;
        else if(n < temp->data)
            temp = temp->left;   
   }
    if(temp != NULL)
    {
        printf("%d\n",balancefactor(temp));
        return balancefactor(root);
    }
    return balancefactor(temp);
}

node* rightRotate(node* root)
{
    node* x = root->left;
    node* temp = x->right;

    x->right = root;
    root->left = temp;

    root->height = 1 + max(height(root->left), height(root->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

node* leftRotate(node* root)
{
    node* x = root->right;
    node* temp = x->left;

    x->left = root;
    root->right = temp;

    root->height = 1 + max(height(root->left), height(root->right));
    x->height = 1 + max(height(x->left), height(x->right));
    
    return x;
}

node* AVL_insert(tree* t,node* root, int n)
{
    if(root == NULL)
        return createnode(n);

    if(root->data > n)
        root->left = AVL_insert(t,root->left,n);
    else if(root->data < n)
        root->right = AVL_insert(t,root->right,n);
    else root;

    root->height = 1 + max(height(root->left),height(root->right));

    int bal = balancefactor(root);

    if(bal > 1 && root->left->data > n)
    {
        t->rightrot++;
        return rightRotate(root);
    }

    if(bal < -1 && root->right->data < n)
    {
        t->leftrot++;
        return leftRotate(root);
    }
    if(bal > 1 && root->left->data <n)
    {
        t->leftrot++;
        root->left = leftRotate(root->left);
        t->rightrot++;
        return rightRotate(root);
    }
    
    if(bal < -1 && root->right->data > n)
    {
        t->rightrot++;
        root->right = rightRotate(root->right);
        t->leftrot++;
        return leftRotate(root);
    }

    return root;
}

int search(node* root, int n)
{
    if(root == NULL)
        return -1;
    if(root->data == n)
        return 1;
    if(n > root->data)
        return search(root->right,n);
    if(n < root->data)
        return search(root->left,n);
    return -1;
}

void AVL_find(node* root, int n)
{
    if(search(root,n) == 1)
    {
        node* temp = root;
        while(temp->data != n)
        {
            printf("%d ",temp->data);
            if(n > temp->data)
                temp = temp->right;
            else temp = temp->left;

        }
        printf("%d\n",temp->data);
    }
    else printf("-1\n");
}

void postorder(node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

node* leftmost(node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

void AVL_rotation(tree* t)
{
    printf("%d %d\n",t->leftrot,t->rightrot);
}

node* AVL_delete(tree* t, node* root, int n)
{
    if (root == NULL)
    {
        printf("-1");
        return NULL;
    }

    if (n > root->data)
    {
        root->right = AVL_delete(t, root->right, n);
    }
    else if (n < root->data)
    {
        root->left = AVL_delete(t, root->left, n);
    }
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            node* temp = NULL;

            if (root->left != NULL)
                temp = root->left;
            else
                temp = root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            node* temp = leftmost(root->right);
            root->data = temp->data;
            root->right = AVL_delete(t, root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int bal = balancefactor(root);

    if (bal > 1 && balancefactor(root->left) >= 0)
    {
        t->rightrot++;
        return rightRotate(root);
    }
    if (bal > 1 && balancefactor(root->left) < 0)
    {
        t->leftrot++;
        root->left = leftRotate(root->left);
        t->rightrot++;
        return rightRotate(root);
    }
    if (bal < -1 && balancefactor(root->right) <= 0)
    {
        t->leftrot++;
        return leftRotate(root);
    }
    if (bal < -1 && balancefactor(root->right) > 0)
    {
        t->rightrot++;
        root->right = rightRotate(root->right);
        t->leftrot++;
        return leftRotate(root);
    }
    return root;
}

void printancestor(node* root,int n)
{
    if(search(root,n) == 1)
    {
        if(root->data == n)
        {
            printf("%d ",root->data);
            return;
        }

        else if(n > root->data)
            printancestor(root->right,n);
        else printancestor(root->left,n);

        printf("%d ",root->data);
    }
    else printf("-1\n");
}

int main()
{
    tree* T = (tree*)malloc(sizeof(tree));

    T->leftrot = T->rightrot = 0;
    T->root = NULL;
    char c = 'A';
    int n;

    while(c != 'e')
    {
        scanf("%c",&c);
        switch (c)
        {
        case 'i':
            scanf("%d",&n);
            if(n < 1 || n > 1000000)
                return 0;
            T->root = AVL_insert(T,T->root,n);
            break;
        case 'f':
            scanf("%d",&n);
            if(n < 1 || n > 1000000)
                return 0;
            AVL_find(T->root,n);
            break;
        case 'p':
            postorder(T->root);
            printf("\n");
            break;
        case 's':
            AVL_rotation(T);
            break;
        case 'd':
            scanf("%d",&n);
            if(n < 1 || n > 1000000)
                return 0;
            printancestor(T->root,n);
            T->root = AVL_delete(T,T->root,n);
            printf("\n");
            break;
        case 'b':
            scanf("%d",&n);
            if(n < 1 || n > 1000000)
                return 0;
            AVL_balanceFactor(T->root,n);
            break;
        case 'e':
            break;
        default:
            break;
        }
    }
    return 0;
}