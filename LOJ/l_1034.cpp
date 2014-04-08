#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int idx,dfn[10010],low[10010],b[10010],d[10010],c[10010],a[100010][2];
stack <int> S;
bool in[10010];
void tarjan(int x)
{
    dfn[x]=low[x]=++idx;
    S.push(x);
    in[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (in[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        c[0]++;
        while (1)
        {
            int y=S.top();
            S.pop();
            in[y]=false;
            c[y]=c[0];
            if (x==y)
                break;
        }
    }
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
        }
        memset(dfn,0,sizeof(dfn));
        idx=c[0]=0;
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i);
        memset(d,0,sizeof(d));
        for (int i=1;i<=n;i++)
            for (int j=b[i];j;j=a[j][1])
            {
                int y=a[j][0];
                if (c[i]!=c[y])
                    d[c[a[j][0]]]++;
            }
        static int id=0;
        printf("Case %d: %d\n",++id,count(d+1,d+c[0]+1,0));
    }
    return(0);
}

