#include <cstdio>
#include <cstring>
int n,b[60],dx[60],dy[60],slack[60],a[60][60];
bool f[60],g[60];
bool hungary(int x)
{
    if (x==0)
        return(true);
    f[x]=true;
    for (int i=1;i<=n;i++)
    {
        if (g[i])
            continue;
        int t=dx[x]+dy[i]-a[x][i];
        if (t==0)
        {
            g[i]=true;
            if (hungary(b[i]))
            {
                b[i]=x;
                return(true);
            }
        }
        else if (t<slack[i])
            slack[i]=t;
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(dx,0,sizeof(dx));
        memset(dy,0,sizeof(dy));
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j]>dx[i])
                    dx[i]=a[i][j];
            }
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            memset(slack,63,sizeof(slack));
            while (1)
            {
                memset(f,0,sizeof(f));
                memset(g,0,sizeof(g));
                if (hungary(i))
                    break;
                int d=1<<30;
                for (int i=1;i<=n;i++)
                    if (!g[i] && slack[i]<d)
                        d=slack[i];
                for (int i=1;i<=n;i++)
                {
                    if (f[i])
                        dx[i]-=d;
                    if (g[i])
                        dy[i]+=d;
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            ans+=a[b[i]][i];
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

