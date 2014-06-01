#include <cstdio>
#include <cstring>
int sum,cnt,v[1010],b[1010],a[20010][2];
bool vis[1010];
void dfs(int x)
{
    vis[x]=true;
    sum+=v[x];
    cnt++;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!vis[y])
            dfs(y);
    }
}
bool solve(int n,int m)
{
    if (m%n!=0)
        return(false);
    m/=n;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
        if (!vis[i])
        {
            sum=cnt=0;
            dfs(i);
            if (cnt*m!=sum)
                return(false);
        }
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,sum=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            sum+=v[i];
        }
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,solve(n,sum)?"Yes":"No");
    }
    return(0);
}

