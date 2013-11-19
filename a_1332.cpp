#include <cstdio>
#include <cstring>
#include <stack>
#include <bitset>
using namespace std;
typedef bitset <110> boolean;
struct edge
{
    int op,x,y;
};
edge e[10010];
int tot,b[110],a[20010][2];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
int idx,N,dfn[110],c[110],low[110];
bool in[110];
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
        N++;
        while (1)
        {
            int y=S.top();
            S.pop();
            in[y]=false;
            c[y]=N;
            if (x==y)
                break;
        }
    }
}
boolean isempty,empty[110],prev[110];
bool check(int mid,int n)
{
    memset(b,0,sizeof(b));
    tot=0;
    for (int i=1;i<=mid;i++)
    {
        if (e[i].op<=2)
            add(e[i].x,e[i].y);
        if (e[i].op==2)
            add(e[i].y,e[i].x);
    }
    idx=N=0;
    memset(dfn,0,sizeof(dfn));
    for (int i=1;i<=n;i++)
        if (!dfn[i])
            tarjan(i);
    memset(b,0,sizeof(b));
    tot=0;
    for (int i=1;i<=mid;i++)
        if (e[i].op==1)
        {
            int x=c[e[i].x],y=c[e[i].y];
            if (x!=y)
                add(x,y);
        }
    for (int i=1;i<=N;i++)
    {
        empty[i].reset();
        prev[i].reset();
        prev[i].set(i);
    }
    isempty.reset();
    for (int i=N;i;i--)
        for (int j=b[i];j;j=a[j][1])
        {
            int x=a[j][0];
            prev[x]|=prev[i];
        }
    for (int i=1;i<=mid;i++)
        if (e[i].op==4)
        {
            int x=c[e[i].x],y=c[e[i].y];
            for (int j=1;j<=N;j++)
            {
                if (prev[x].test(j))
                    empty[j]|=prev[y];
                if (prev[y].test(j))
                    empty[j]|=prev[x];
                if (prev[x].test(j) && prev[y].test(j))
                    isempty|=prev[j];
            }
        }
    for (int i=1;i<=mid;i++)
    {
        if (e[i].op==3)
        {
            int x=c[e[i].x],y=c[e[i].y];
            if (x==y || isempty.test(x) && isempty.test(y))
                return(false);
        }
        if (e[i].op==5)
        {
            int x=c[e[i].x],y=c[e[i].y];
            if (isempty.test(x) || isempty.test(y) || empty[x].test(y) || empty[y].test(x))
                return(false);
        }
    }
    return(true);
}
int main()
{
    while (1)
    {
        
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=m;i++)
            scanf("%d%d%d",&e[i].op,&e[i].x,&e[i].y);
        int l=1,r=m,ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(mid,n))
                ans=mid,l=mid+1;
            else
                r=mid-1;
        }
        printf("%d\n",ans);
    }
    return(0);
}

