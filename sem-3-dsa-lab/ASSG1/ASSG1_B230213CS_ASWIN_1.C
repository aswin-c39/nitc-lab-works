#include<stdio.h>
#include<stdlib.h>

typedef struct Tnode{
    int data;
    struct Tnode* left;
    struct Tnode* right;
}Tnode;


Tnode* createnode(int data)
{
    Tnode* newnode = (Tnode*)malloc(sizeof(Tnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    } 
    return -1;
}

struct Tnode* buildTree(int in[], int pre[], int inStart, int inEnd, int *preIndex) {
    if(inStart>inEnd)
        return NULL;
    
    int val = pre[*preIndex];
    (*preIndex)++;

    Tnode* root = createnode(val);

    if(inStart == inEnd)
        return root;
    int inInd = search(in,inStart,inEnd,val);

    root->left = buildTree(in,pre,inStart,inInd-1,preIndex);
    root->right = buildTree(in,pre,inInd+1,inEnd,preIndex);

    return root;

    
}

void postOrder(struct Tnode* node) {
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

int height(Tnode* root)
{
    if(root == NULL)
        return 0;
    
    int lheight = height(root->left);
    int rheight = height(root->right);

    if(lheight>rheight) return lheight+1;

    return rheight+1;
}

void printlvl(Tnode* root,int lvl,int ltr)
{
    if(root == NULL) return;

    if(lvl == 1)
        printf("%d ",root->data);
    else if(lvl>1)
    {
        if(ltr)
        {
            printlvl(root->left,lvl-1,ltr);
            printlvl(root->right,lvl-1,ltr);
        } else {
            printlvl(root->right,lvl-1,ltr);
            printlvl(root->left,lvl-1,ltr);
        }
    }
}

void zigzag(Tnode* root)
{
    int h = height(root);
    int ltr = 0;
    for(int i = 1;i <= h;i++){
        printlvl(root,i,ltr);
        ltr = !ltr;
    }
    printf("\n");
}

void getmax(Tnode* root,int lvl,int*max)
{
    if(root == NULL) return;

    if(lvl == 1)
    {
        if(root->data > *max)
            *max = root->data;
    }
    else if(lvl > 1)
    {
        getmax(root->left,lvl-1,max);
        getmax(root->right,lvl-1,max);
    }
}

void levelmax(Tnode* root)
{
    if(root == NULL) return;

    int h = height(root);
    for(int i = 1;i<=h;i++)
    {
        int max = -1;
        getmax(root,i,&max);
        printf("%d ",max);
    }
    printf("\n");
}



int diameter(Tnode* root,int* h)
{
    int lh = 0,rh = 0;
    int ldm = 0,rdm = 0;

    if(root == NULL){
        *h = 0;
        return 0;
    }

    ldm = diameter(root->left,&lh);
    rdm = diameter(root->right,&rh);

    if(lh>rh)
        *h = lh+1;
    else *h = rh+1;

    int maxdm ;
    if(ldm>rdm)
        maxdm = ldm;
    else    
        maxdm = rdm;
    

    if(lh+rh+1 > maxdm)
        return lh+rh+1;
    else    
        return maxdm;
}

int rightleafsum(Tnode* root,int*sum)
{
    if(root == NULL)
        return 0;
        if(root->right != NULL && root->right->left ==NULL && root->right->right == NULL)
            *sum += root->right->data;
        rightleafsum(root->left,sum);
        rightleafsum(root->right,sum);
}

int main() {
    int n;
    scanf("%d",&n);
    if(n<=1 || n>1000000)
        return 0; 

    int in[n],pre[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&in[i]);
        if(in[i]<=1 || in[i]>1000000)
           return 0;
    }
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&pre[i]);    
        if(in[i]<=1 || in[i]>1000000)
            return 0;
    }
    int preInd = 0;
    Tnode* root = buildTree(in,pre,0,n-1,&preInd);

    char c = 'A';

    while(c!='e')
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'p':
                postOrder(root);
                printf("\n");
                break;
            case 'z':
                zigzag(root);
                break;
            case 'm':
                levelmax(root);
                break;
            case 'd':
                int h = 0;
                printf("%d\n",diameter(root,&h));
                break;
            case 's':
                int sum = 0;
                rightleafsum(root,&sum);
                printf("%d\n",sum);
                break;
            default:
                continue;
        }
    }
    return 0;
}