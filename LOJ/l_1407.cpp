#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int n,m,K,tot,b[2010],choose[10],p[10][4],e[2010][3],a[1000000][2];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
int idx,dfn[2010],low[2010],c[2010];
bool in[2010];
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
            s.pop();
            c[y]=c[0],in[y]=false;
            if (x==y)
                break;
        }
    }
}
bool solve()
{
    tot=0;
    memset(b,0,sizeof(b));
    for (int i=1;i<=m;i++)
    {
        int op=e[i][0],x=e[i][1],y=e[i][2];
        if (op==1)
        {
            add(x+n,y);
            add(y+n,x);
        }
        else if (op==2)
        {
            add(x+n,y+n);
            add(y,x);
        }
        else if (op==3)
        {
            add(x,y+n);
            add(y,x+n);
        }
        else
        {
            add(x,y+n);
            add(x+n,y);
            add(y,x+n);
            add(y+n,x);
        }
    }
    for (int i=1;i<=K;i++)
    {
        int op=p[i][0],x=choose[i];
        if (op==1)
            add(x+n,x);
        else
            add(x,x+n);
    }
    memset(dfn,0,sizeof(dfn));
    idx=c[0]=0;
    for (int i=1;i<=2*n;i++)
        if (!dfn[i])
            tarjan(i);
    for (int i=1;i<=n;i++)
        if (c[i]==c[i+n])
            return(false);
    printf("Possible ");
    int cnt=0;
    for (int i=1;i<=n;i++)
        cnt+=c[i]<c[i+n];
    printf("%d",cnt);
    for (int i=1;i<=n;i++)
        if (c[i]<c[i+n])
            printf(" %d",i);
    printf(".\n");
    return(true);
}
bool dfs(int dep)
{
    if (dep==K+1)
        return(solve());
    for (int i=1;i<=3;i++)
    {
        choose[dep]=p[dep][i];
        if (dfs(dep+1))
            return(true);
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=m;i++)
            scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
        for (int i=1;i<=K;i++)
            scanf("%d%d%d%d",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
        static int id=0;
        printf("Case %d: ",++id);
        if (!dfs(1))
            printf("Impossible.\n");
    }
    return(0);
}

