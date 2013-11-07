#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,idx,dfn[5010],low[5010],b[5010],ans[5010],a[10010][2];
void tarjan(int x,int father,int ban)
{
    ans[x]=0;
    dfn[x]=low[x]=++idx;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father || y==ban)
            continue;
        if (!dfn[y])
        {
            tarjan(y,x,ban);
            low[x]=min(low[x],low[y]);
            if (low[y]>=dfn[x])
                ans[x]++;
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
    if (father==0)
        ans[x]--;
}
int calc(int ban)
{
    memset(dfn,0,sizeof(dfn));
    idx=0;
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (i==ban || dfn[i])
            continue;
        cnt++;
        tarjan(i,0,ban);
    }
    int ret=0;
    for (int i=1;i<=n;i++)
    {
        if (i==ban)
            continue;
        ret=max(ret,cnt+ans[i]);
    }
    return(ret);
}
int main()
{
    int m;
    while (scanf("%d%d",&n,&m)==2)
    {
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            ans=max(ans,calc(i));
        printf("%d\n",ans);
    }
    return(0);
}

