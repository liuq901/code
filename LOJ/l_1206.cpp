#include <cstdio>
#include <cstdlib>
#include <cstring>
bool vis[510],a[510][510];
int sx[510],sy[510],tx[510],ty[510],start[510],b[510];
int dist(int x0,int y0,int x1,int y1)
{
    return(abs(x0-x1)+abs(y0-y1));
}
bool hungary(int x,int n)
{
    if (x==0)
        return(true);
    for (int y=1;y<=n;y++)
    {
        if (vis[y] || !a[x][y])
            continue;
        vis[y]=true;
        if (hungary(b[y],n))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d:%d%d%d%d%d",&x,&y,&sx[i],&sy[i],&tx[i],&ty[i]);
            start[i]=x*60+y;
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                a[i][j]=start[i]+dist(sx[i],sy[i],tx[i],ty[i])+dist(tx[i],ty[i],sx[j],sy[j])<start[j];
        memset(b,0,sizeof(b));
        int ans=n;
        for (int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            ans-=hungary(i,n);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

