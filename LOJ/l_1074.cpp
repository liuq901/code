#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int vis[210],d[210],w[210],b[210],a[1000000][2];
bool in[210];
int f(int x)
{
    return(x*x*x);
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
            scanf("%d",&w[i]);
        int m;
        scanf("%d",&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
        }
        memset(d,63,sizeof(d));
        queue <int> Q;
        Q.push(1);
        d[1]=0;
        in[1]=true;
        memset(vis,0,sizeof(vis));
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            in[x]=false;
            for (int i=b[x];i;i=a[i][1])
            {
                int y=a[i][0];
                if (d[x]+f(w[y]-w[x])<d[y])
                {
                    d[y]=d[x]+f(w[y]-w[x]);
                    if (!in[y])
                    {
                        if (++vis[y]>n)
                            continue;
                        in[y]=true;
                        Q.push(y);
                    }
                }
            }
        }
        static int id=0;
        printf("Case %d:\n",++id);
        int q;
        scanf("%d",&q);
        while (q--)
        {
            int x;
            scanf("%d",&x);
            if (d[x]==d[0] || d[x]<3)
                printf("?\n");
            else
                printf("%d\n",d[x]);
        }
    }
    return(0);
}

