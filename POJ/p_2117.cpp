#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a[10010];
int id,ans,root,dfn[10010],low[10010];
void tarjan(int x)
{
    dfn[x]=low[x]=++id;
    int sum=0;
    for (int i=0;i<a[x].size();i++)
    {
        int y=a[x][i];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
            if (low[y]>=dfn[x])
                sum++;
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
    if (x==root)
        ans=max(ans,sum-1);
    else
        ans=max(ans,sum);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (!n && !m)
            break;
        for (int i=1;i<=n;i++)
            a[i].clear();
        while (m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        memset(dfn,0,sizeof(dfn));
        ans=-1<<30;
        id=0;
        int sum=0;
        for (int i=1;i<=n;i++)
            if (!dfn[i])
            {
                sum++;
                root=i;
                tarjan(i);
            }
        printf("%d\n",ans+sum);
    }
    return(0);
}

