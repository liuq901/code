#include <cstdio>
#include <vector>
using namespace std;
vector <int> a[100010];
bool vis[100010];
int dep[100010];
void dfs(int x)
{
    for (int i=0;i<a[x].size();i++)
    {
        int y=a[x][i];
        dep[y]=dep[x]+1;
        dfs(y);
    }
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
        {
            a[i].clear();
            vis[i]=false;
        }
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            vis[y]=true;
        }
        int root;
        for (int i=1;i<=n;i++)
            if (!vis[i])
            {
                root=i;
                break;
            }
        dep[root]=0;
        dfs(root);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%s\n",dep[x]<=dep[y]?"lxh":"pfz");
        }
    }
    return(0);
}

