#include<stdio.h>

int largestprime(int N)
{
    for(int i = N-1 ; i > 2 ; i--)
    {
        int isprime = 1;
        for(int j = 2 ; j <= i/2 ; j++)
        {
            if(i % j == 0)
            {
                isprime = 0;
                break;
            }
            
        }

        if(isprime)
            return i;
    }
    return 2;
}

int secondaryhash(int n,int N)
{
    int R = largestprime(N);
    return R - (n % R);
}

int linearhashing(int n,int j,int N)
{
    return ((n + j) % N);
}

int quadratichashing(int n,int j,int N)
{
    return ((n + (j*j)) % N);
}

int doublehashing(int n,int j,int N)
{
    int h2 = secondaryhash(n,N);
    //printf("check : %d %d\n",h2,largestprime(N));
    return (((n%N) + j*h2) % N);
}


void LinearProbing(int* num, int N, int m)
{
    int temp[N];
    int collision = 0;

    for(int i = 0 ; i < N ; i++)
    {
        temp[i] = -1;
    }

    for(int i = 0 ; i < m ; i++)
    {
        int j = 0;
        while(1)
        {
            int n = linearhashing(num[i], j, N);

            if(temp[n] == -1) 
            {
                temp[n] = num[i];
                break;
            }
            collision++;
            j++;
        }
    }

    for(int i = 0 ; i < m ; i++)
    {
        int j = 0;
        while(1)
        {
            int n = linearhashing(num[i], j, N);
            j++;

            if(temp[n] == num[i])
            {
                printf("%d ",n);
                break;
            }
        }
    }

    printf("\n");

    printf("%d\n",collision);

}

void QuadraticProbing(int* num, int N, int m)
{
    int temp[N];
    int collision = 0;

    for(int i = 0 ; i < N ; i++)
    {
        temp[i] = -1;
    }

    for(int i = 0 ; i < m ; i++)
    {
        int j = 0;
        
        while(1)
        {
            int n = quadratichashing(num[i], j, N);
            j++;

            if(temp[n] == -1)
            {
                temp[n] = num[i];
                break;
            }

            collision++;
        }
    }

    for(int i = 0 ; i < m ; i++)
    {
        int j = 0;
        while(1)
        {
            int n = quadratichashing(num[i], j, N);
            j++;

            if(temp[n] == num[i])
            {
                printf("%d ",n);
                break;
            }
        }
    }

    printf("\n");

    printf("%d\n",collision);

}

void DoubleHashing(int* num,int N,int m)
{
    int temp[N];
    int collision = 0;

    for(int i = 0 ; i < N ; i++)
    {
        temp[i] = -1;
    }

    for(int i = 0 ; i < m ; i++)
    {
        int j = 0;
        
        while(1)
        {
            int n = doublehashing(num[i], j, N);
            j++;

            if(temp[n] == -1)
            {
                temp[n] = num[i];
                break;
            }

            collision++;
        }
    }

    for(int i = 0 ; i < m ; i++)
    {
        int j = 0;
        while(1)
        {
            int n = doublehashing(num[i], j, N);
            j++;

            if(temp[n] == num[i])
            {
                printf("%d ",n);
                break;
            }
        }
    }

    printf("\n");

    printf("%d\n",collision);

}

int main()
{
    int N,m;
    scanf("%d%d",&N,&m);

    int num[m];

    for(int i = 0 ; i < m ; i++)
    {
        scanf("%d",&num[i]);
    }

    char c = 'A';

    while(c != 'd')
    {
        scanf("%c",&c);

        switch(c)
        {
            case 'a':
                LinearProbing(num,N,m);
                break;
            case 'b':
                QuadraticProbing(num,N,m);
                break;
            case 'c':
                DoubleHashing(num,N,m);
                break;
        }
    }
    return 0;
}