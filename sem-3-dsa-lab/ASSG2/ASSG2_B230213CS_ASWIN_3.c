#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 1000

typedef struct node{
    int key,height;
    struct node *left,*right;
}node;

typedef struct stack{
    char A[MAX];
    int top;
}stack;

void push(stack* stack,char n)
{
    if(stack->top == MAX-1)
    {
        return;
    }
    (stack->top)++;
    stack->A[stack->top] = n;
}

char pop(stack* stack)
{
    if(stack->top == -1)
    {
        return -1;
    }
    return stack->A[(stack->top)--];
}

char peek(stack stack)
{
    if(stack.top == -1)
    {
        printf("Stack Empty\n");
    }
    return stack.A[stack.top];
}

node* createnode(int key)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->key = key;
    newnode->height = 0; 
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
    if(root == NULL)
        return -1;
    return root->height;
}

void preorder(node* root)
{
    if(root == NULL)
        return;

    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}

node* leftmost(node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node* rightmost(node* root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node* search(node* root, int n)
{
    if(root == NULL)
        return NULL;
    if(root->key == n)
        return root;
    if(n > root->key)
        return search(root->right,n);
    if(n < root->key)
        return search(root->left,n);
    return NULL;
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

void removeSpace(char *s)
{
    int j = 0;
    for(int i = 0; s[i] != '\0';i++)
    {
        if(s[i] != ' ')
            s[j++] = s[i];
    }
    s[j] = '\0';
}

char* readPara()
{
    char buf[MAX];
    fgets(buf,MAX,stdin);
    buf[strcspn(buf, "\n")] = '\0';
    char* a = (char*)malloc((strlen(buf) + 1) * sizeof(char));
    strcpy(a,buf);
    removeSpace(a);
    return a;
}

int findindex(char str[], int s, int e)
{
    if(s > e)
        return -1;
    
    stack S;
    S.top = -1;

    for(int i = s; i < e; i++)
    {
        if(str[i] == '(')
            push(&S,str[i]);
        
        else if(str[i] == ')')
        {
            if(peek(S) == '(')
                pop(&S);
            
            if(S.top == -1)
                return i;
        }
        
    }

    return -1;

}

node* stringToBst(char* str,node* root,int s, int e)
{
    if(s>e)
        return NULL;
    int n = 0;

    while(s <= e && str[s] >= '0' && str[s] <= '9')
    {
        n *= 10;
        n += (str[s] - '0');
        s++; 
    }

    root = createnode(n);
    int ind = -1;

    if(s <= e && str[s] == '(')
        ind = findindex(str,s,e);

    if(ind != -1)
    {
        root->left = stringToBst(str,root->left,s+1,ind-1);
        root->right = stringToBst(str,root->right,ind+2,e-1);
    }

    root->height = 1 + max(height(root->left),height(root->right));
    return root;
}

node* AVL_insert(node* root, int n) {
    if (root == NULL) {
        return createnode(n);
    }

    if (n < root->key) {
        root->left = AVL_insert(root->left, n);
    } else if (n > root->key) {
        root->right = AVL_insert(root->right, n);
    } else {
        return root;
    }

    root->height = 1 + max(height(root->left),height(root->right));

    int bal = balancefactor(root);

    if (bal > 1 && n < root->left->key) {
        return rightRotate(root);
    }

    if (bal < -1 && n > root->right->key) {
        return leftRotate(root);
    }

    if (bal > 1 && n > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bal < -1 && n < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void pararep(node* root)
{
    if(root == NULL)
        return;
    printf("%d",root->key);

    if(root->left != NULL || root->right !=NULL)
    {
        printf(" (");
        if(root->left != NULL)
        {
            printf(" ");
            pararep(root->left);
        }

        printf(" )");

        if(root->right != NULL)
        {
            printf(" ( ");
            pararep(root->right);
            printf(" )");
        }
        else printf(" ( )");
    }
}

node* AVL_SeqInsert(node* root, int* key, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        root = AVL_insert(root,key[i]);
    }

    pararep(root);
    printf("\n");
    return root;
}

int* charToInt(int* count) {
    int* arr = NULL;
    int num = 0;
    int inNumber = 0;  
    char c;

    *count = 0;

    while ((c = getchar()) != '\n') {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');  
            inNumber = 1;
        } else if (inNumber) {

            arr = (int*) realloc(arr, (*count + 1) * sizeof(int));
            arr[*count] = num;
            (*count)++;
            num = 0;
            inNumber = 0;
        }
    }

    if (inNumber) {
        arr = (int*) realloc(arr, (*count + 1) * sizeof(int));
        arr[*count] = num;
        (*count)++;
    }

    return arr;
}

node* AVL_delete(node* root, int n) {
    if (root == NULL)
        return NULL;

    if (n > root->key)
        root->right = AVL_delete(root->right, n);
    else if (n < root->key)
        root->left = AVL_delete(root->left, n);
    else {
        if (root->left == NULL || root->right == NULL) {
            node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp; 
            }
            free(temp);
        } else {
            node* temp = leftmost(root->right);

            root->key = temp->key;

            root->right = AVL_delete(root->right, temp->key);
        }
    }


    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int bal = balancefactor(root);

    if (bal > 1 && balancefactor(root->left) >= 0)
        return rightRotate(root);

    if (bal > 1 && balancefactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bal < -1 && balancefactor(root->right) <= 0)
        return leftRotate(root);

    if (bal < -1 && balancefactor(root->right) > 0) {
        root->right = rightRotate(root->right);  
        return leftRotate(root);
    }

    return root;
}

node* AVL_RangeDelete(node* root, int n1, int n2,int* count)
{
    if(root == NULL)
        return NULL;
    if(root->key < n1)
        root->right = AVL_RangeDelete(root->right,n1,n2,count);
    else if(root->key > n2)
        root->left = AVL_RangeDelete(root->left,n1,n2,count);
    else{
        (*count)++;
        root = AVL_delete(root,root->key);
        root = AVL_RangeDelete(root,n1,n2,count);
    }

    if(root)
    {
        root->height = 1 + max(height(root->left), height(root->right));
        int bal = balancefactor(root);

        if (bal > 1 && balancefactor(root->left) >= 0)
        return rightRotate(root);

        if (bal > 1 && balancefactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (bal < -1 && balancefactor(root->right) <= 0)
            return leftRotate(root);

        if (bal < -1 && balancefactor(root->right) > 0) {
            root->right = rightRotate(root->right);  
            return leftRotate(root);
        }
    }
    return root;
}

node* successor(node* root,int k)
{
    node* a = search(root,k);

    if(root == NULL)
        return NULL;
    
    if(a->right != NULL)
        return leftmost(a->right);
    
    node* suc = NULL;
    while(root != NULL)
    {
        if(a->key < root->key)
        {
            suc = root;
            root = root->left;
        }
        else if(a->key > root->key)
            root = root->right; 
        else break;
    }

    return suc;
}

node* predeccesoor(node *root, int key)
{
    node* a = search(root,key);

    if(root == NULL)
        return NULL;
    
    if(a->left != NULL)
        return rightmost(a->right);
    
    node* pred = NULL;
    while(root != NULL)
    {
        if(a->key > root->key)
        {
            pred = root;
            root = root->right;
        }
        else if(a->key > root->key)
            root = root->left; 
        else break;
    }

    return pred;
}

void printPath(node* root,node* s)
{
    node* temp = root;
    if(root == s)
    {
        printf("%d ",root->key);
        return;
    }
    while(temp != s)
    {
        printf("%d ",temp->key);
        if(s->key > temp->key)
            temp = temp->right;
        else if(s->key < temp->key)
            temp = temp->left;
    }
    printf("%d ",temp->key);
    printf("\n");
}

void AVL_SuccessorPath(node* root, int n)
{
    if(root == NULL)
        return;
   node* s = successor(root,n);
   if(s == NULL)
        printf("%d\n",root->height);
    else printPath(root,s);
}

int sum(node* root)
{
    if(root == NULL)
        return 0;
    return sum(root->left) + sum(root->right) + root->key;
}

int AVL_SubtreeSum(node* root,int n)
{
    node* temp = search(root,n);

    if(temp == NULL)
        return -1;
    
    return sum(temp);
}

int AVL_FindClosest(node* root, int n)
{
    if(search(root,n) == NULL)
        return -1;
    
    node* suc = successor(root,n);
    node* pred = predeccesoor(root,n);

    if(suc == NULL && pred == NULL)
        return -1;
    
    if(suc == NULL)
        return pred->key;
    if (pred == NULL)
        return suc->key;
    
    if((suc->key - n) > (n - pred->key))
        return pred->key;

    else if((n - pred->key) > (suc->key - n))
        return suc->key;

    return pred->key;
}

void printheight(node* root)
{
    if(root == NULL)
        return;
    printf("%d %d\n",root->key,root->height);
    printheight(root->left);
    printheight(root->right);
}

int main(){

    node* root = NULL;
    char buffer[1000];
    char c = 'A';
    int* keys;
    int count = 0,n1,n2;
    node* x = NULL;
    char *input = readPara();
    //printf("%s",input);
    root = stringToBst(input,root,0,strlen(input));
    //preorder(root);

    while(c != 'g')
    {
        scanf("%c",&c);

        switch(c)
        {
            case 'a':
                getchar();
                count = 0;
                keys = charToInt(&count);
                //printf("%d",count);
                root = AVL_SeqInsert(root,keys,count);
                //preorder(root);
                break;
            case 'b':
                scanf("%d%d",&n1,&n2);
                count = 0;
                root = AVL_RangeDelete(root,n1,n2,&count);
                printf("%d ",count);
                //printheight(root);
                preorder(root);
                //pararep(root);
                printf("\n");
                break;
            case 'c':
                scanf("%d",&n1);
                AVL_SuccessorPath(root,n1);
                break;
            case 'd':
                scanf("%d",&n1);
                x = search(root,n1);
                printf("%d ",AVL_SubtreeSum(root,n1));
                pararep(x);
                printf("\n");
                break;
            case 'e':
                scanf("%d",&n1);
                printf("%d\n",AVL_FindClosest(root,n1));
                break;
            default:
                break;
        }
    }
    return 0;
}