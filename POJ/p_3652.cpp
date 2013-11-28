#include <cstdio>
#include <cstring>
int f[30];
bool vis[66000];
void fill(int S)
{
    for (int i=0;i<16;i++)
    {
        int x=S>>i&1;
        if (x==f[i])
            continue;
        f[i]=-1;
    }
}
int main()
{
    int A,B,C,S;
    while (scanf("%d%d%d%d",&A,&B,&C,&S)==4)
    {
        memset(vis,0,sizeof(vis));
        for (int i=0;i<16;i++)
            f[i]=S>>i&1;
        while (1)
        {
            if (vis[S])
                break;
            vis[S]=true;
            fill(S);
            S=(A*S+B)%C;
        }
        for (int i=15;i>=0;i--)
            if (f[i]==-1)
                printf("?");
            else
                printf("%d",f[i]);
        printf("\n");
    }
    return(0);
}

