#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
bool choose[100010];
int tot,b[100010],a[1000000][2];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
int idx,c[100010],dfn[100010],low[100010],rev[100010];
bool in[100010];
stack <int> S;
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
            in[y]=false,c[y]=c[0];
            if (x==y)
                break;
        }
    }
}
bool calc(int n)
{
    for (int i=1;i<=2*n;i++)
        if (!dfn[i])
            tarjan(i);
    for (int i=1;i<=2*n;i++)
    {
        if (c[i]==c[rev[i]])
            return(false);
        choose[i]=c[i]<c[rev[i]];
    }
    return(true);
}
int ans[50010],pos[50010],color[50010],to[100010];
int main()
{
    freopen("chip.in","r",stdin);
    freopen("chip.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&color[i]);
    for (int i=1;i<=2*n;i++)
    {
        int x;
        scanf("%d",&x);
        to[i]=x;
        if (pos[x]==0)
            pos[x]=i;
        else
        {
            rev[i]=pos[x];
            rev[pos[x]]=i;
        }
    }
    for (int i=1;i<=2*n;i++)
    {
        int x=i==1?2*n:i-1;
        int y=i==2*n?1:i+1;
        if (color[to[i]]==color[to[x]])
        {
            add(i,rev[x]);
            add(x,rev[i]);
        }
        if (color[to[i]]==color[to[y]])
        {
            add(i,rev[y]);
            add(y,rev[i]);
        }
    }
    if (calc(n))
    {
        printf("YES\n");
        for (int i=1;i<=2*n;i++)
            if (choose[i])
               ans[to[i]]=i;
        for (int i=1;i<=n;i++)
            printf("%d%c",ans[i],i==n?'\n':' ');
    }
    else
        printf("NO\n");
    return(0);
}

