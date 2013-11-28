#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int P=50;
int n,ans[2010],vis[2010],dep[2010],e[1010][2],a[2010][2010];
void dfs(int x)
{
    for (int i=1;i<=a[x][0];i++)
    {
        int y=a[x][i];
        if (!vis[y])
        {
            dep[y]=dep[x]+1;
            vis[y]=vis[x];
            dfs(y);
        }
    }
}
int q[2010];
int calc(int S)
{
    int l,r,ret=0;
    memset(dep,0,sizeof(dep));
    q[l=r=1]=S;
    dep[S]=1;
    while (l<=r)
    {
        int x=q[l++];
        if (dep[x]==P+1)
            dep[x]=P-1;
        ret=max(ret,dep[x]);
        for (int i=1;i<=a[x][0];i++)
        {
            int y=a[x][i];
            if (!dep[y])
            {
                dep[y]=dep[x]+1;
                q[++r]=y;
            }
        }
    }
    return(ret-1);
}
int main()
{
    int m;
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[i][0]=x,e[i][1]=y;
        a[x][++a[x][0]]=y;
        a[y][++a[y][0]]=x;
    }
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (!vis[i])
        {
            vis[i]=++cnt;
            dep[i]=1;
            dfs(i);
        }
    bool flag=true;
    for (int i=1;i<=m;i++)
    {
        int x=e[i][0],y=e[i][1];
        if (abs(dep[x]-dep[y])%2==0)
        {
            flag=false;
            break;
        }
    }
    if (!flag)
        printf("-1\n");
    else if (cnt>=2)
    {
        printf("%d\n",P-1);
        for (int i=1;i<=n;i++)
        {
            int ans;
            if (vis[i]&1)
                ans=dep[i]&1?1:2;
            else
                ans=dep[i]&1?P:P-1;
            printf("%d%c",ans,i==n?'\n':' ');
        }
    }
    else
    {
        int answer=0;
        for (int i=1;i<=n;i++)
        {
            int now=calc(i);
            if (now>answer)
            {
                answer=now;
                memcpy(ans,dep,sizeof(dep));
            }
        }
        printf("%d\n",answer);
        for (int i=1;i<=n;i++)
            printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return(0);
}

