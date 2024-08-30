#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,max=0,maxcount=0;
    scanf("%d",&n);
    char **strings;
    getchar();
    strings=(char**)malloc(n*sizeof(char*));

    char *string;
    string=(char*)malloc(0);
    char c;
    
    for (int i = 0; i < n; i++)
    {
        int count=0;

        while((c=getchar())!='\n')
        {
            string=(char*)realloc(string,(count+1)*sizeof(char));
            string[count++]=c;
        }
        string[count]='\0';
        strings[i]=(char*)malloc(count+1);
        strcpy(strings[i],string);
        if(maxcount<=count)
        {
            maxcount=count;
            max=i;
        }
    }

    printf("\n%s",strings[max]);
    free(string);

    for (int i = 0; i < n; i++)
    {
        free(strings[i]);
    }
    free(strings);
    return 0;
}