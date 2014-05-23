#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
int tot,d[200010],b[200010],a[300010][2];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
    d[y]++;
}
int dep[200010];
void dfs(int x)
{
    dep[x]=1;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (dep[y]==0)
            dfs(y);
        dep[x]=max(dep[x],dep[y]+1);
    }
}
priority_queue <pair <int,int> > Q;
void update(int x)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (--d[y]==0)
            Q.push(make_pair(dep[y],y));
    }
}
int topsort(int n)
{
    for (int i=1;i<=n;i++)
        if (dep[i]==0)
            dfs(i);
    for (int i=1;i<=n;i++)
        if (d[i]==0)
            Q.push(make_pair(dep[i],i));
    int ans=0;
    while (!Q.empty())
    {
        ans++;
        int x=Q.top().second;
        Q.pop();
        if (!Q.empty())
        {
            int y=Q.top().second;
            Q.pop();
            update(y);
        }
        update(x);
    }
    return(ans);
}
int main()
{
    freopen("documents.in","r",stdin);
    freopen("documents.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        add(i,i+n);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x+n,y);
    }
    printf("%.2f\n",topsort(n)/2.0);
    return(0);
}

