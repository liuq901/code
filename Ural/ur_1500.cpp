#include <cstdio>
#include <cstring>
bool vis[40];
int a[40][40];
void dfs(int x,int n,int now)
{
    vis[x]=true;
    for (int i=0;i<n;i++)
        if ((a[x][i]&now) && !vis[i])
            dfs(i,n,now);
}
int getbit(int x)
{
    int ans=0;
    while (x)
    {
        ans+=x&1;
        x>>=1;
    }
    return(ans);
}
int main()
{
    int K,n,m;
    scanf("%d%d%d",&K,&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]|=1<<z;
        a[y][x]|=1<<z;
    }
    int ans=(1<<K)-1;
    for (int i=0;i<1<<K;i++)
    {
        if (getbit(i)>=getbit(ans))
            continue;
        memset(vis,0,sizeof(vis));
        dfs(0,n,i);
        if (vis[1])
            ans=i;
    }
    printf("%d\n",getbit(ans));
    bool first=true;
    for (int i=0;i<K;i++)
        if (ans>>i&1)
        {
            if (!first)
                printf(" ");
            first=false;
            printf("%d",i);
        }
    printf("\n");
    return(0);
}

