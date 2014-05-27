#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int idx,c[20010],dfn[20010],low[20010],b[20010],in[20010],out[20010],a[50010][2];
stack <int> s;
bool flag[20010];
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
            c[y]=c[0],flag[y]=false;
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
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for (int i=1;i<=n;i++)
            for (int j=b[i];j;j=a[j][1])
            {
                int x=a[j][0];
                if (c[i]!=c[x])
                {
                    out[c[i]]++;
                    in[c[x]]++;
                }
            }
        static int id=0;
        printf("Case %d: ",++id);
        if (c[0]==1)
            printf("0\n");
        else
            printf("%d\n",max(count(in+1,in+c[0]+1,0),count(out+1,out+c[0]+1,0)));
    }
    return(0);
}

