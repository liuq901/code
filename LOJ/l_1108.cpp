#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int d[1010],cnt[1010],b[1010],a[2010][3];
bool in[1010],vis[1010];
void dfs(int x)
{
    vis[x]=true;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (vis[y])
            continue;
        dfs(y);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i][0]=x,a[i][1]=z,a[i][2]=b[y],b[y]=i;
        }
        memset(d,0,sizeof(d));
        memset(cnt,0,sizeof(cnt));
        queue <int> Q;
        for (int i=1;i<=n;i++)
        {
            Q.push(i);
            in[i]=true;
        }
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            in[x]=false;
            for (int i=b[x];i;i=a[i][2])
            {
                int y=a[i][0];
                if (d[x]+a[i][1]<d[y])
                {
                    d[y]=d[x]+a[i][1];
                    if (!in[y] && cnt[y]<=n)
                    {
                        cnt[y]++;
                        in[y]=true;
                        Q.push(y);
                    }
                }
            }
        }
        static int id=0;
        printf("Case %d:",++id);
        bool flag=true;
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++)
            if (cnt[i]>n)
                dfs(i);
        for (int i=1;i<=n;i++)
            if (vis[i])
            {
                printf(" %d",i-1);
                flag=false;
            }
        if (flag)
            printf(" impossible");
        printf("\n");
    }
    return(0);
}

