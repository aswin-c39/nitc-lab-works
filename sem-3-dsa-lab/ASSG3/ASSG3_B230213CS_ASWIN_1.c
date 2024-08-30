#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct student
{
    char name[20];
    char roll[10];
    int age;
}student;

typedef struct node
{
    student* s;
    struct node* next;

}node;

void swap(node* a, node* b) {
    char temp[20];
    strcpy(temp, a->s->name);
    strcpy(a->s->name, b->s->name);
    strcpy(b->s->name, temp);
}

int hash(char* name,int age)
{
    int h = age, i = 0;

    while(name[i] != '\0')
    {
        h += (int)name[i];
        i++;
    }

    return h % 4;
}

node* insert(node* head, student* stu)
{
    
    if(head == NULL)
    {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->s = stu;
        newnode->next = NULL;
        return newnode;
    }

    head->next = insert(head->next,stu);

    return head;
}

int GroupIndexAndSplit(char* name, node* H[])
{
    for(int i = 0 ; i < 4 ; i++)
    {
        node* temp = H[i];
        while(temp != NULL)
        {
            if(strcmp(name,temp->s->name) == 0)
                return hash(name,temp->s->age);
            temp = temp->next;
        }
    }
    return -1;
}

void print(node* head)
{
    while(head != NULL)
    {
        printf("%s ",head->s->name);
        head = head->next;
    }
    printf("\n");
}


void Group_CountAndList(node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    int count = 0;
    node* temp = head;


    while (temp != NULL) {
        count++;
        temp = temp->next;
    }



    for (node* i = head; i != NULL; i = i->next) {
        node* min = i;
        for (node* j = i->next; j != NULL; j = j->next) {
            if (strcmp(j->s->name, min->s->name) < 0) {
                min = j;
            }
        }
        if (min != i) {
            student* tempStu = i->s;
            i->s = min->s;
            min->s = tempStu;
        }
    }

    temp = head;

    printf("%d ", count);

    while (temp != NULL) {
        printf("%s ", temp->s->name);
        temp = temp->next;
    }
    printf("\n");
}



void Group_ListByBranch(node* H[], int k, char* branch)
{
    node* temp = H[k];

    if(islower(branch[0]))
        branch[0] = toupper(branch[0]);
    if(islower(branch[1]))
        branch[1] = toupper(branch[1]);

    int flag = 0;
    while(temp != NULL)
    {
        char str[3] = {temp->s->roll[7],temp->s->roll[8],'\0'};
        if(strcmp(branch,str) == 0)
        {
            printf("%s ",temp->s->name);
            flag = 1;
        }
        temp = temp->next;
    }
    
    if(flag == 0)
        printf("-1");
    printf("\n");
}

void StudentDetails(node* H[],char* roll)
{
    int flag = 0;

    for(int i = 0 ; i < 4 ; i++)
    {
        node* temp = H[i];
        while(temp != NULL)
        {
            if(strcmp(roll,temp->s->roll) == 0)
            {
                printf("%s %d %c%c\n",temp->s->name,temp->s->age,roll[7],roll[8]);
                flag = 1;
            }
            temp = temp->next;
        }
    }
    
    if(!flag)
        printf("-1\n");

}

node* delete(node* head, node* Node)
{
    node* cur = head,*prev =NULL;
    while(cur != Node)
    {
        if(cur == NULL)
        {
            return head;
        }

        prev = cur;
        cur = cur->next;
    }
    if(prev == NULL)
    {
        head = cur->next;
        return head;
    }
    
    prev->next = cur->next;
    free(cur);
    return head;
}

void Group_TransferAllByBranch(node* H[],int source,int target,char* branch)
{
    node* temp = H[source];
    int count = 0;

    if(islower(branch[0]))
        branch[0] = toupper(branch[0]);
    if(islower(branch[1]))
        branch[1] = toupper(branch[1]);
    while(temp != NULL)
    {
        if(temp->s->roll[7] == branch[0] && temp->s->roll[8] == branch[1])
        {
            count++;
            H[target] = insert(H[target],temp->s);
            node* dlt = temp;
            temp = temp->next;
            H[source] = delete(H[source],dlt);
        }
        else temp = temp->next;
        
    }
    printf("%d\n",count);
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    int age,k;
    student stu[n];
    char name[20], roll[10];
    node* H[4] = {NULL,NULL,NULL,NULL};

    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s%s%d",stu[i].name,stu[i].roll,&stu[i].age);
        //printf("1\n");
        int h = hash(stu[i].name,stu[i].age);
        //printf("2\n");
        H[h] = insert(H[h],&stu[i]);
    }

    char c = 'A';
    char branch[3];
    int s,t;

    while (c != 'f')
    {
        scanf("%c",&c);

        switch(c)
        {
            case 'a':
                scanf("%s",name);
                printf("%d\n",GroupIndexAndSplit(name,H));
                break;
            case 'b':
                scanf("%d",&s);
                //printf("1\n");
                Group_CountAndList(H[s]);
                break;
            case 'c':
                scanf("%d%s",&k,branch);
                Group_ListByBranch(H, k, branch);
                break;
            case 'd':
                scanf("%s",roll);
                StudentDetails(H,roll);
                break;
            case 'e':   
                scanf("%d%d%s",&s,&t,branch);
                Group_TransferAllByBranch(H,s,t,branch);
                break;
            case 'p':
                scanf("%d",&s);
                print(H[s]);
                break;
            default:
                break;
        }
    }

    return 0;
}