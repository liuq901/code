#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int idx,c[10010],dfn[10010],low[10010],b[10010],a[40010][2];
stack <int> s;
void tarjan(int x,int father)
{
    dfn[x]=low[x]=++idx;
    s.push(x);
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (!dfn[y])
        {
            tarjan(y,x);
            low[x]=min(low[x],low[y]);
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        c[0]++;
        while (1)
        {
            int y=s.top();
            s.pop();
            c[y]=c[0];
            if (x==y)
                break;
        }
    }
}
int d[10010];
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
            x++,y++;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        memset(dfn,0,sizeof(dfn));
        idx=c[0]=0;
        tarjan(1,0);
        memset(d,0,sizeof(d));
        for (int i=1;i<=n;i++)
            for (int j=b[i];j;j=a[j][1])
            {
                int x=a[j][0];
                if (c[i]!=c[x])
                    d[c[x]]++;
            }
        static int id=0;
        printf("Case %d: ",++id);
        if (c[0]==1)
            printf("0\n");
        else
            printf("%d\n",count(d+1,d+c[0]+1,1)+1>>1);
    }
    return(0);
}

