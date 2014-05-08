#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int idx,dfn[10010],low[10010],b[10010],a[40010][2];
bool ans[10010];
void tarjan(int x,int father)
{
    dfn[x]=low[x]=++idx;
    int cnt=0;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (!dfn[y])
        {
            cnt++;
            tarjan(y,x);
            low[x]=min(low[x],low[y]);
            if (low[y]>=dfn[x] && x!=1)
                ans[x]=true;
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
    if (x==1)
        ans[1]=cnt>=2;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        memset(ans,0,sizeof(ans));
        memset(dfn,0,sizeof(dfn));
        idx=0;
        tarjan(1,0);
        static int id=0;
        printf("Case %d: %d\n",++id,count(ans+1,ans+n+1,true));
    }
    return(0);
}

