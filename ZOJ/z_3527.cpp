#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=100010;
const ll inf=1LL<<60;
bool ring[maxn];
int d[maxn],v[maxn],g[maxn],p[maxn],l[maxn],r[maxn],last[maxn],next[maxn];
ll f[maxn][2];
queue <int> Q;
void addedge(int x,int y)
{
    if (!l[x])
        l[x]=y;
    else
        r[last[x]]=y;
    last[x]=y;
}
void topsort(int n)
{
    for (int i=1;i<=n;i++)
    {
        if (!d[i])
            Q.push(i);
        ring[i]=true;
    }
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        ring[x]=false;
        d[p[x]]--;
        if (d[p[x]]==0)
            Q.push(p[x]);
    }
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    for (int i=1;i<=n;i++)
        if (ring[i])
            next[i]=p[i];
        else
            addedge(p[i],i);
}
void dp(int x)
{
    f[x][0]=0,f[x][1]=v[x];
    for (int i=l[x];i;i=r[i])
    {
        dp(i);
        f[x][0]+=max(f[i][0],f[i][1]);
        f[x][1]+=max(f[i][0],f[i][1]+g[i]);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        memset(d,0,sizeof(d));
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&v[i],&g[i],&p[i]);
            d[p[i]]++;
        }
        topsort(n);
        for (int i=1;i<=n;i++)
            if (ring[i])
                dp(i);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            if (!ring[i])
                continue;
            int S=i;
            ll x,y,now=-inf;
            int prev;
            x=f[S][0],y=-inf;
            prev=S;
            for (int i=next[S];i!=S;i=next[i])
            {
                ll p=f[i][0]+max(x,y),q=f[i][1]+max(x,y+g[prev]);
                x=p,y=q;
                prev=i;
            }
            now=max(now,max(x,y));
            x=-inf,y=f[S][1];
            prev=S;
            for (int i=next[S];i!=S;i=next[i])
            {
                ll p=f[i][0]+max(x,y),q=f[i][1]+max(x,y+g[prev]);
                x=p,y=q;
                prev=i;
            }
            now=max(now,max(x,y+g[prev]));
            ans+=now;
            for (int i=next[S];i!=S;i=next[i])
                ring[i]=false;
            ring[S]=false;
        }
        printf("%lld\n",ans);
    }
    return(0);
}

