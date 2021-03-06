#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
bool vis[30],a[30][30];
int d[30];
vector <int> adj[30];
inline bool cmp(int x,int y)
{
    if (d[x]!=d[y])
        return(d[x]<d[y]);
    return(x<y);
}
void dfs(int x)
{
    vis[x]=true;
    for (int i=0;i<adj[x].size();i++)
    {
        int y=adj[x][i];
        if (!vis[y])
        {
            dfs(y);
            break;
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x!=y)
            a[x][y]=a[y][x]=true;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j])
            {
                d[i]++;
                adj[i].push_back(j);
            }
    for (int i=1;i<=n;i++)
        sort(adj[i].begin(),adj[i].end(),cmp);
    bool flag=false;
    for (int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        dfs(i);
        if (count(vis+1,vis+n+1,true)==n)
        {
            flag=true;
            break;
        }
    }
    printf("%s\n",flag?"Yes":"No");
    return(0);
}

