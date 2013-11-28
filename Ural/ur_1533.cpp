#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N=110;
bool vis[N],a[N][N];
int n,b[N];
vector <int> p;
void dfs(int x)
{
    vis[x]=true;
    for (int i=1;i<=n;i++)
        if (!vis[i] && a[x][i])
            dfs(i);
}
bool hungary(int x)
{
    if (x==0)
        return(true);
    for (int y=1;y<=n;y++)
    {
        if (vis[y] || !a[x][y])
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
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (a[i][k] && a[k][j])
                    a[i][j]=true;
    int ans=n;
    for (int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ans-=hungary(i);
    }
    printf("%d\n",ans);
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
        vis[b[i]]=true;
    for (int i=1;i<=n;i++)
        if (!vis[i])
            p.push_back(i);
    while (1)
    {
        bool flag=false;
        for (int i=0;i<p.size();i++)
        {
            memset(vis,0,sizeof(vis));
            int x=p[i];
            dfs(x);
            vis[x]=false;
            for (int j=0;j<p.size();j++)
                if (vis[p[j]])
                {
                    flag=true;
                    while (vis[p[j]])
                        p[j]=b[p[j]];
                }
        }
        if (!flag)
            break;
    }
    for (int i=0;i<p.size();i++)
        printf("%d%c",p[i],i==p.size()-1?'\n':' ');
    return(0);
}

