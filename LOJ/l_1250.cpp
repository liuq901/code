#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int b[210],a[100000][2];
bool vis[100000];
vector <int> p;
void dfs(int x)
{
    for (int i=b[x];i;i=a[i][1])
    {
        if (vis[i])
            continue;
        int y=a[i][0];
        vis[i]=vis[i^1]=true;
        dfs(y);
    }
    p.push_back(x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans+=x;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans-n*(n+1)/2-m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[2*i][0]=y,a[2*i][1]=b[x],b[x]=2*i;
            a[2*i+1][0]=x,a[2*i+1][1]=b[y],b[y]=2*i+1;
        }
        memset(vis,0,sizeof(vis));
        p.clear();
        dfs(1);
        for (int i=0;i<p.size();i++)
            printf("%d%c",p[i],i+1==p.size()?'\n':' ');
    }
    return(0);
}

