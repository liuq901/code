#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int idx,in[1010],out[1010],dfn[1010],low[1010],b[1010],c[1010],d[1010],a[10010][2],e[10010][2];
bool flag[1010];
stack <int> s;
void tarjan(int x)
{
    dfn[x]=low[x]=++idx;
    s.push(x);
    flag[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (flag[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        c[0]++;
        while (1)
        {
            int y=s.top();
            s.pop();
            flag[y]=false,c[y]=c[0];
            if (y==x)
                break;
        }
    }
}
bool calc(int n,int m)
{
    memset(b,0,sizeof(b));
    for (int i=1;i<=m;i++)
    {
        int x=e[i][0],y=e[i][1];
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
    }
    memset(dfn,0,sizeof(dfn));
    idx=c[0]=0;
    tarjan(1);
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for (int i=1;i<=m;i++)
    {
        int x=e[i][0],y=e[i][1];
        if (!dfn[x] || !dfn[y])
            return(false);
        if (c[x]==c[y])
            continue;
        out[c[x]]++;
        in[c[y]]++;
    }
    if (c[0]==1)
        return(true);
    for (int i=2;i<c[0];i++)
        if (in[i]!=1 || out[i]!=1)
            return(false);
    return(in[1]==1 && out[1]==0 && in[c[0]]==0 && out[c[0]]==1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int K;
            scanf("%d",&K);
            for (int j=1;j<=K;j++)
            {
                m++;
                scanf("%d%d",&e[m][0],&e[m][1]);
                e[m][0]++,e[m][1]++;
            }
        }
        static int id=0;
        printf("Case %d: %s\n",++id,calc(1000,m)?"YES":"NO");
    }
    return(0);
}

