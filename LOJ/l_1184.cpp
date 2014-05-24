#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,m,b[60];
bool vis[60],a[60][60];
bool hungary(int x)
{
    if (x==0)
        return(true);
    for (int y=1;y<=m;y++)
    {
        if (!a[x][y] || vis[y])
            continue;
        vis[y]=true;
        if (hungary(b[y]))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
int h[60],age[60],f[60];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d%d%d",&h[i],&age[i],&f[i]);
        memset(a,0,sizeof(a));
        for (int i=1;i<=m;i++)
        {
            int H,A,F;
            scanf("%d%d%d",&H,&A,&F);
            for (int j=1;j<=n;j++)
                if (abs(H-h[j])<=12 && abs(A-age[j])<=5 && F==f[j])
                    a[j][i]=true;
        }
        int ans=0;
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            ans+=hungary(i);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

