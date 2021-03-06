#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[100010],p[100010],b[100010],a[200010][2];
bool vis[100010];
int dfs(int x)
{
    vis[x]=true;
    int ret=1;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!vis[y])
            ret+=dfs(y);
    }
    return(ret);
}
bool check(int x)
{
    while (x)
    {
        int p=x%10;
        if (p!=4 && p!=7)
            return(false);
        x/=10;
    }
    return(true);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
    }
    for (int i=1;i<=n;i++)
        if (!vis[i])
            p[dfs(i)]++;
    memset(f,63,sizeof(f));
    int inf=f[0];
    f[0]=0;
    for (int i=1;i<=n;i++)
    {
        if (!p[i])
            continue;
        for (int j=1;p[i];j<<=1)
        {
            int x=min(j,p[i]);
            p[i]-=x;
            for (int k=n-x*i;k>=0;k--)
                f[k+x*i]=min(f[k+x*i],f[k]+x);
        }
    }
    int ans=inf;
    for (int i=1;i<=n;i++)
        if (check(i))
            ans=min(ans,f[i]);
    if (ans==inf)
        ans=0;
    printf("%d\n",ans-1);
    return(0);
}

