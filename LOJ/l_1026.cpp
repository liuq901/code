#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int tot,idx,dfn[10010],low[10010],b[10010],a[200010][2];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=b[y],b[y]=tot;
}
vector <pair <int,int> > ans;
void tarjan(int x,int pre)
{
    dfn[x]=low[x]=++idx;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (i==pre)
            continue;
        if (!dfn[y])
        {
            tarjan(y,i^1);
            low[x]=min(low[x],low[y]);
            if (low[y]==dfn[y])
                ans.push_back(make_pair(min(x,y),max(x,y)));
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        tot=1;
        for (int i=1;i<=n;i++)
        {
            int x,K;
            scanf("%d (%d)",&x,&K);
            x++;
            for (int j=1;j<=K;j++)
            {
                int y;
                scanf("%d",&y);
                y++;
                if (x<y)
                    add(x,y);
            }
        }
        memset(dfn,0,sizeof(dfn));
        idx=0;
        ans.clear();
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i,0);
        sort(ans.begin(),ans.end());
        static int id=0;
        printf("Case %d:\n%d critical links\n",++id,ans.size());
        for (int i=0;i<ans.size();i++)
            printf("%d - %d\n",ans[i].first-1,ans[i].second-1);
    }
    return(0);
}

