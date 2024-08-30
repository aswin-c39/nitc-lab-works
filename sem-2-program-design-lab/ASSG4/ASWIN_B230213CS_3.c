#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


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

node* createTree(char str[],int start,int end)
{
    if(start>end)
        return NULL;
    int n=-1;
    while(start<=end && str[start]>='0' && str[start]<='9')
    {
        if(n==-1)
        {
            n=0;
        }
        n=n*10 + (str[start]-'0');
        start++;
    }
        if(n==-1)
            return NULL;
        node* root=createnode(n);
        int ind=-1;
        int count=0;
        for(int i=start;i<=end;i++)
        {
            if(str[i]=='(')
                count++;
            else if(str[i]==')')
            {
                count--;
                if(count==0)
                {
                    ind =i;
                    break;
                }
            }
        }
        if(ind!=-1)
        {
            root->left=createTree(str,start+1,ind-1);
            root->right=createTree(str,ind+2,end-1);
        }
        return root;
    
}


void skipSpace(char* str)
{
    int j=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]!=' ')
            str[j++]=str[i];
    }
    str[j]='\0';
}

node *SearchNode(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->key == key)
    {
        return root;
    }
    node *left = SearchNode(root->left, key);
    if (left != NULL)
    {
        return left;
    }

    return SearchNode(root->right, key);
}

void printdepth(node *root, int *k)
{

    if (root == NULL || *k < 0)
    {
        return;
    }
    int depth = *k;
    if (depth == 0)
    {
        printf("%d ", root->key);
        return;
    }
    depth--;
    printdepth(root->left, &depth);
    printdepth(root->right, &depth);
}

int main()
{
    int n=0;
    node* root=NULL;
    char str[1000000];
    getchar();
    fgets(str,1000000,stdin);
    str[strcspn(str,"\n")]='\0';
    if(str[0]=='\0')
    return 0;

    char cpy[1000000];
    int dig[1000000];
    dig[0]=-1;
    strcpy(cpy,str);
    int j=0;
    int ind=0;
    while(cpy[j]!='\0')
    {
        if(isdigit(cpy[j]))
        {
            dig[ind]=atoi(&cpy[j]);
            ind++;
            while(isdigit(cpy[j]))
            {
                j++;
            }
        }
        else
            j++;
        
    }

    if(ind>1000)
        return 0;
    dig[ind]=-1;
    for(int i=0;dig[i]!=-1;i++)
    {
        if(dig[i]<1 || dig[i]>1000000)
            return 0;
    }
    skipSpace(str);
    root=createTree(str,0,strlen(str)-1);
    int x,k;
    scanf("%d %d",&x,&k);
    if(k<1 ||k>1000)
        return 0;

    node *target=SearchNode(root,x);
    printdepth(target,&k);
    printf("\n");
    return 0; 
}