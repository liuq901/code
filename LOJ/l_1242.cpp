#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
namespace matching
{
    int idx,tot,vis[110],b[110],to[110],a[10010][2];
    void clear()
    {
        tot=0;
        memset(b,0,sizeof(b));
        memset(to,0,sizeof(to));
    }
    void add(int x,int y)
    {
        a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
    }
    bool hungary(int x)
    {
        if (x==0)
            return(true);
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (vis[y]==idx)
                continue;
            vis[y]=idx;
            if (hungary(to[y]))
            {
                to[y]=x;
                return(true);
            }
        }
        return(false);
    }
    bool solve(int n)
    {
        for (int i=1;i<=n;i++)
        {
            idx++;
            if (!hungary(i))
                return(false);
        }
        return(true);
    }
}
vector <int> a[110],b[110];
int f[110][110];
bool dp(int x0,int father0,int x1,int father1)
{
    if (f[x0][x1]!=-1)
        return(f[x0][x1]);
    int u=0,v;
    bool tmp[a[x0].size()][b[x1].size()];
    for (int i=0;i<a[x0].size();i++)
    {
        if (a[x0][i]==father0)
            continue;
        v=0;
        for (int j=0;j<b[x1].size();j++)
        {
            if (b[x1][j]==father1)
                continue;
            tmp[u][v]=dp(a[x0][i],x0,b[x1][j],x1);
            v++;
        }
        u++;
    }
    matching::clear();
    for (int i=1;i<=u;i++)
        for (int j=1;j<=v;j++)
            if (tmp[i-1][j-1])
                matching::add(i,j);
    return(f[x0][x1]=matching::solve(u));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
            b[i].clear();
        for (int i=1;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            b[x].push_back(y);
            b[y].push_back(x);
        }
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            a[i].clear();
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        memset(f,-1,sizeof(f));
        static int id=0;
        printf("Case %d: %s\n",++id,dp(1,0,1,0)?"Yes":"No");
    }
    return(0);
}

