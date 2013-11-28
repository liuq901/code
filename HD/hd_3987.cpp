#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mul=1000000;
const ll inf=1LL<<60;
int S,T,tot,b[1010],a[200010][2];
ll c[200010];
void add(int x,int y,ll v1,ll v2)
{
    a[++tot][0]=y,a[tot][1]=b[x],c[tot]=v1,b[x]=tot;
    a[++tot][0]=x,a[tot][1]=b[y],c[tot]=v2,b[y]=tot;
}
int d[1010],q[1010];
bool build()
{
    memset(d,0,sizeof(d));
    int l,r;
    q[l=r=1]=S;
    d[S]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (d[y] || !c[i])
                continue;
            d[y]=d[x]+1;
            q[++r]=y;
            if (y==T)
                return(true);
        }
    }
    return(false);
}
ll dinic(int x,ll flow)
{
    if (x==T)
        return(flow);
    ll k=flow;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (d[y]!=d[x]+1 || !c[i])
            continue;
        ll t=dinic(y,min(k,c[i]));
        k-=t;
        c[i]-=t;
        c[i^1]+=t;
        if (!k)
            return(flow);
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z,p;
            scanf("%d%d%d%d",&x,&y,&z,&p);
            ll v=ll(mul)*z+1;
            if (p==0)
                add(x,y,v,0);
            else
                add(x,y,v,v);
        }
        S=0,T=n-1;
        ll ans=0;
        while (build())
            ans+=dinic(S,inf);
        static int id=0;
        printf("Case %d: %d\n",++id,int(ans%mul));
    }
    return(0);
}

