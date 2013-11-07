#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int ans,tot,idx,f[1010],b[1010],a[2000010][3];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int dfn[1010],low[1010];
void tarjan(int x,int pre)
{
    dfn[x]=low[x]=++idx;
    for (int i=b[x];i;i=a[i][2])
    {
        if (i==pre)
            continue;
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y,i^1);
            low[x]=min(low[x],low[y]);
            if (low[y]>=dfn[y] && (ans==-1 || a[i][1]<ans))
                ans=a[i][1];
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
}
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=z,a[tot][2]=b[y],b[y]=tot;
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
            f[i]=i;
        memset(b,0,sizeof(b));
        tot=1;
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            f[find(x)]=find(y);
            add(x,y,z);
        }
        ans=-1;
        for (int i=1;i<=n;i++)
            if (find(i)!=find(1))
            {
                ans=0;
                break;
            }
        if (ans==-1)
        {
            idx=0;
            memset(dfn,0,sizeof(dfn));
            tarjan(1,-1);
            if (ans==0)
                ans=1;
        }
        printf("%d\n",ans);
    }
    return(0);
}

