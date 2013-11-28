#include <cstdio>
#include <cstring>
int c[110],a[110][110];
bool vis[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(a,63,sizeof(a));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if (z<a[x][y])
                a[x][y]=a[y][x]=z;
        }
        int ans=0;
        memset(c,63,sizeof(c));
        memset(vis,0,sizeof(vis));
        c[0]=0;
        for (int i=0;i<=n;i++)
        {
            int k=n+1;
            for (int j=0;j<=n;j++)
                if (!vis[j] && c[j]<c[k])
                    k=j;
            if (k==n+1)
            {
                ans=-1;
                break;
            }
            vis[k]=true;
            ans+=c[k];
            for (int j=0;j<=n;j++)
                if (!vis[j] && a[k][j]<c[j])
                    c[j]=a[k][j];
        }
        printf("%d\n",ans);
    }
    return(0);
}

