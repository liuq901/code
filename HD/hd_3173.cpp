#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int N=100010;
int idx,c[N],dfn[N],low[N],b[N],d[N],a[N][2];
bool in[N];
stack <int> s;
void tarjan(int x)
{
    dfn[x]=low[x]=++idx;
    in[x]=true;
    s.push(x);
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
            int y=s.top();
            s.pop(),in[y]=false;
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
        idx=c[0]=0;
        memset(dfn,0,sizeof(dfn));
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i);
        memset(d,0,sizeof(d));
        for (int i=1;i<=n;i++)
            for (int j=b[i];j;j=a[j][1])
            {
                int x=a[j][0];
                if (c[i]==c[x])
                    continue;
                d[c[x]]++;
            }
        printf("%d\n",count(d+1,d+c[0]+1,0));
    }
    return(0);
}

